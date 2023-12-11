# 网络编程（Windows端）

## 步骤

> 1. 网络环境初始化：WSAStartup
> 2. 创建服务器套接字：socket
> 3. 绑定本机IP和端口：bind
> 4. 监听客户端：listen
> 5. 等待客户端连接：accept
> 6. 发送消息：send
> 7. 接收消息：recv
> 8. 关闭socket：closesocket
> 9. 清除网络环境：WSACleanup

## 常用函数

1. `int WSAStartUp(WORD wVersionRequest,LPWSADATA lpWSAData)`
2. `int WSACleanup() 成功返回0,失败返回SOCKET_ERROR`
3. `SOCKET socket(int af,int type,int protocol);成功时返回套接字句柄，失败返回INVALID_SOCKET`
4. `int bind(SOCKET s,const struct sockaddr*name,int namelen);返回0,SOCKET_ERROR`
5. `int listen(SOCKET s,int backlog);0,SOCKET_ERROR`
6. `SOCKET accept(SOCKET s,struct sockaddr*addr,int*addrlen);`
7. `int connect(SOCKET s,const struct sockaddr* name,int namelen);`
8. `int closesocket(SOCKET s);`
Windows区分《文件句柄》和《套接字句柄》
