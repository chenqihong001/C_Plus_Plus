#include <iostream>
#include <WinSock2.h>
void ErrorHandling(const char *message);
int main()
{
    WSADATA WSAData;                // 关于版本信息的结构体
    SOCKET hServSock, hClntSock;    // SOCKET->unsigned _int64
    SOCKADDR_IN servAddr, clntAddr; // 两个地址，SOCKETADDR_IN->(sin_family,sin_port,sin_addr,sin_zero[8])
}

void ErrorHandling(const char *message)
{
    std::cout << message;
}