#include "EchoServerMultIOThread.h"

EchoServerMultIOThread::EchoServerMultIOThread(EventLoop* pLoop, NetAddress addr, int threadNum)
    :_pLoop(pLoop)
    ,_pServer(pLoop, addr)
{
    _pServer.setCallback(this);
    _pServer.setThreadNum(threadNum);
}

EchoServerMultIOThread::~EchoServerMultIOThread()
{}

void EchoServerMultIOThread::start()
{
    _pServer.start();
    //_threadpool.start(3); //计算线程池
}

void EchoServerMultIOThread::onConnection(TcpConnection* pCon)
{
    cout << "EchoServerMultIOThread::onConnection tid = " << CurrentThread::tid() << endl;
}

void EchoServerMultIOThread::onMessage(TcpConnection* pCon, Buffer* pBuf)
{
    string msg(pBuf->retrieveAllAsString());
    cout << "EchoServerMultIOThread::onMessage tid = " << CurrentThread::tid() << " recv " << msg.size() << " bytes" 
        << " data " << msg << endl;
    pCon->send(msg + "\n");
    //_threadpool.addTask(std::bind(&EchoServerMultIOThread::echo, this, msg, pCon));
}

void EchoServerMultIOThread::onWriteComplate(TcpConnection* pCon)
{
    cout << "EchoServerMultIOThread::onWriteComplate tid = " << CurrentThread::tid() << endl;
}

void EchoServerMultIOThread::onClose(TcpConnection* pCon)
{
    cout << "EchoServerMultIOThread::onClose tid = " << CurrentThread::tid() << endl;
}

//回显方法 多计算线程时使用
void EchoServerMultIOThread::echo(const string& str, void* param)
{
    cout << "EchoServerMultIOThread::echo SEND tid = " << CurrentThread::tid() << endl;
    TcpConnection *pTcpCon = static_cast<TcpConnection*>(param);
    pTcpCon->send(str + "\n");
}