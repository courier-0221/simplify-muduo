#include "EchoServerSingleCalcThread.h"

EchoServerSingleCalcThread::EchoServerSingleCalcThread(EventLoop* pLoop, NetAddress addr)
    :_pLoop(pLoop)
    ,_pServer(pLoop, addr)
{
    _pServer.setCallback(this);
}

EchoServerSingleCalcThread::~EchoServerSingleCalcThread()
{}

void EchoServerSingleCalcThread::start()
{
    _pServer.start();
}

void EchoServerSingleCalcThread::onConnection(TcpConnection* pCon)
{
    cout << "EchoServerSingleCalcThread::onConnection" << endl;
}

void EchoServerSingleCalcThread::onMessage(TcpConnection* pCon, Buffer* pBuf)
{
    string msg(pBuf->retrieveAllAsString());
    cout << "EchoServerSingleCalcThread::onMessage" << " recv " << msg.size() << " bytes " 
        << "SEND tid = " << CurrentThread::tid() << endl;
    pCon->send(msg + "\n");
}

void EchoServerSingleCalcThread::onWriteComplate(TcpConnection* pCon)
{
    cout << "EchoServerSingleCalcThread::onWriteComplate" << endl;
}

void EchoServerSingleCalcThread::onClose(TcpConnection* pCon)
{
    cout << "EchoServerSingleCalcThread::onClose" << endl;
}