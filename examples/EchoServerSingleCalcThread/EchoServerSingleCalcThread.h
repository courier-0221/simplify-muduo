#ifndef ECHOSERVERSINGLECALCTHREAD_H
#define ECHOSERVERSINGLECALCTHREAD_H

#include "ICommonCallback.h"
#include "TcpServer.h"
#include "ThreadPool.h"
#include "Acceptor.h"
#include "TcpConnection.h"
#include "EventLoop.h"
#include "CurrentThread.h"

#include <iostream>

class EchoServerSingleCalcThread : public IMuduoUser
{
public:
    EchoServerSingleCalcThread(EventLoop* pLoop, NetAddress addr);
    ~EchoServerSingleCalcThread();
    void start();
    virtual void onConnection(TcpConnection* pCon);
    virtual void onMessage(TcpConnection* pCon, Buffer* pBuf);
    virtual void onWriteComplate(TcpConnection* pCon);
    virtual void onClose(TcpConnection* pCon);
private:
    EventLoop* _pLoop;
    TcpServer _pServer;
};

#endif
