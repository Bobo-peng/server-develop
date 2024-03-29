// udpclient.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
void udpclient()
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
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(30000);
	//connect(fd, (SOCKADDR*)&clientsock_in, sizeof(SOCKADDR));//开始连接
	while (1)
	{
		int len = sizeof(addr);
		char achBuf[1024] = { 0 };
		memcpy(achBuf, "111", 3);
		int buflen = strlen(achBuf);
		int ret = sendto(fd, achBuf, buflen, 0, (struct sockaddr*)&addr, len);
		memset(achBuf, 0, 1024);
		memcpy(achBuf, "222", 3);
		buflen = strlen(achBuf);
		ret = sendto(fd, achBuf, buflen, 0, (struct sockaddr*)&addr, sizeof(addr));
		memset(achBuf, 0, 1024);
		memcpy(achBuf, "333", 3);
		buflen = strlen(achBuf);
		ret = sendto(fd, achBuf, buflen, 0, (struct sockaddr*)&addr, sizeof(addr));

	}
	//关闭socket连接
	closesocket(fd);
	//清理
	WSACleanup();
}
int  udpclient1()
{
	WSAData wsd;           //初始化信息
	SOCKET soSend;         //发送SOCKET
	int nRet = 0;
	//int i = 0;
	int dwSendSize = 0;
	SOCKADDR_IN siLocal;    //远程发送机地址和本机接收机地址

							//启动Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0) {/*进行WinSocket的初始化,
												windows 初始化socket网络库，申请2，2的版本，windows socket编程必须先初始化。*/
		std::cout << "WSAStartup Error = " << WSAGetLastError() << std::endl;
		return 0;
	}

	//创建socket

	//AF_INET 协议族:决定了要用ipv4地址（32位的）与端口号（16位的）的组合
	//SOCK_DGRAM --  UDP类型，不保证数据接收的顺序，非可靠连接；
	soSend = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (soSend == SOCKET_ERROR) {
		std::cout << "socket Error = " << WSAGetLastError() << std::endl;
		return 1;
	}

	//设置端口号
	int nPort = 5150;
	siLocal.sin_family = AF_INET;
	siLocal.sin_port = htons(nPort);
	siLocal.sin_addr.s_addr = inet_addr("127.0.0.1");

	for (int i = 0; i < 30; i++) {
		//开始发送数据
		//发送数据到指定的IP地址和端口
		nRet = sendto(soSend, "123 mutouren", strlen("123 mutouren"), 0, (SOCKADDR*)&siLocal, sizeof(SOCKADDR));
		if (nRet == SOCKET_ERROR) {
			std::cout << "sendto Error " << WSAGetLastError() << std::endl;
			break;
		}
	}
	//关闭socket连接
	closesocket(soSend);
	//清理
	WSACleanup();

	return 0;
	
}
int main()
{
	udpclient();
	return 0;
}
