// udpserver.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
void udpserver()
{
	//1. 初始化套接字库
	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(1, 1);
	int nError = WSAStartup(wVersionRequested, &wsaData);
	if (nError != 0)
		return;

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return;
	}

	//2. 创建用于监听的套接字
	SOCKET fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	SOCKADDR_IN addr;
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(30000);
	//3. 绑定套接字
	if (bind(fd, (SOCKADDR*)&addr, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		closesocket(fd);
		WSACleanup();
		return;
	}
	while (1)
	{
		int len = sizeof(addr);
		char buf[1024] = { 0 };
		Sleep(10000);
		int nRet = recvfrom(fd, buf, 1024, 0, (SOCKADDR*)&addr, &len);
		printf("conn = %s\n", buf);

	}
}
int main()
{
	udpserver();
	getchar();
	return 0;
}

