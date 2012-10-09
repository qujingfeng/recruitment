#include <winsock2.h>
#include <stdio.h>
#include <iostream>
#pragma comment( lib, "ws2_32.lib" )  
using namespace std;
void main()
{
    WSADATA wsaData;
    SOCKET ClientSocket;
    SOCKADDR_IN ServerAddr;
    int ServerPort = 59000;
    char ServerIPAddr[50] = "127.0.0.1";
    //char *SendData = "search";
	char SendData[10];
    char ReceiveBuffer[1024] = "";
	//char ReceiveBuffer[1024] = "";
    int SendLength =  - 1;
    int Result =  - 1;
    if ((Result = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
    {
        printf("WSAStartup failed with error %d\n", Result);
        return ;
    }
    ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ClientSocket < 0)
    {
        printf("socket failed with error %d\n", WSAGetLastError());
        return ;
    }
    memset(&ServerAddr, 0, sizeof(ServerAddr));
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(ServerPort);
    ServerAddr.sin_addr.s_addr = inet_addr(ServerIPAddr);
    Result = connect(ClientSocket, (SOCKADDR*) &ServerAddr, sizeof(ServerAddr));
    if (Result < 0)
    {
        printf("connect failed with error %d\n", WSAGetLastError());
        return ;
    }
	cout<<"please input command"<<endl;
	cin>>SendData;
    printf("strlen:%d\n", strlen(SendData));
    SendLength = send(ClientSocket, SendData, strlen(SendData), 0);
    if (SendLength < 0)
    {
        printf("send failed with error %d\n", WSAGetLastError());
        return ;
    }
    else
    {
        printf("Send Data:%s\n", SendData);
    }
    int ReceiveLen;
    memset(ReceiveBuffer, 0, sizeof(ReceiveBuffer));
    if ((ReceiveLen = recv(ClientSocket, ReceiveBuffer, 1024, 0)) < 0)
    {
        printf("recv failed with error %d\n", WSAGetLastError());
        return ;
    }
    else
    {
        printf("Receive Data:%s\n", ReceiveBuffer);
    }

	int SendLength2;
	char reloadfile[10];
	cout<<"Please input filename"<<endl;
	cin>>reloadfile;
	SendLength2 = send(ClientSocket,reloadfile,strlen(reloadfile),0);
	if (SendLength2 < 0)
	{
		cout<<"send data error"<<endl;
		return;
	}
	else
	{
		cout<<"send data is:"<<reloadfile<<endl;
	}



    if (closesocket(ClientSocket) == SOCKET_ERROR)
    {
        printf("closesocket failed with error %d\n", WSAGetLastError());
    }
    if (WSACleanup() == SOCKET_ERROR)
    {
        printf("WSACleanup failed with error %d\n", WSAGetLastError());
    }
}
