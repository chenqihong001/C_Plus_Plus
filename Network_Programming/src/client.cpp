#include <iostream>
#include <WinSock2.h>
// 1.int WSAStartUp(WORD wVersionRequest,LPWSADATA lpWSAData)
// 2.int WSACleanup() 成功返回0,失败返回SOCKET_ERROR
// 3.SOCKET socket(int af,int type,int protocol);成功时返回套接字句柄，失败返回INVALID_SOCKET
// 4.int bind(SOCKET s,const struct sockaddr* name,int namelen);返回0,SOCKET_ERROR
// 5.int listen(SOCKET s,int backlog);0,SOCKET_ERROR
// 6.SOCKET accept(SOCKET s,struct sockaddr* addr,int *addrlen);
// 7.int connect(SOCKET s,const struct sockaddr* name,int namelen);
// 8.int closesocket(SOCKET s);
// Windows区分《文件句柄》和《套接字句柄》
int main()
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "WSAStartUp() error!";
    }
    WSACleanup();
    return 0;
}