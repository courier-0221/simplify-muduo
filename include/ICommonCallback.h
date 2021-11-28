#ifndef ICOMMONCALLBACK_H
#define ICOMMONCALLBACK_H

#include "Common.h"
#include <string>
using namespace std;

class IChannelCallback
{
public:
    virtual void handleRead() = 0;
    virtual void handleWrite() = 0;
    virtual void handleClose() = 0;
};

class IAcceptorCallback
{
public:
    virtual void newConnection(int sockfd) = 0; //新客户端连接上服务器 服务端视角
};

class IConnectorCallback
{
public:
    virtual void newConnection(int sockfd) = 0; //客户端与服务器建立了连接 客户端视角
};

class IMuduoUser
{
public:
    virtual void onConnection(TcpConnection* pCon) = 0;
    virtual void onMessage(TcpConnection* pCon, Buffer* pBuf) = 0;
    virtual void onWriteComplate(TcpConnection* pCon) = 0;
    virtual void onClose(TcpConnection* pCon) = 0;
};

#endif