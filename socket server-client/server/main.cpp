#include <winsock2.h>
#include <stdio.h>
#include <iostream>
#include "server_process.h"
#include <fstream>
#include <stdlib.h>
#include <string>
#include <fcntl.h>
#include <io.h>
#include <sys\stat.h>
#pragma comment( lib, "ws2_32.lib" ) 
using namespace std;

void main()
{
	WSADATA wsaData;
    SOCKET ServerSocket;
    SOCKET NewSocket;
    SOCKADDR_IN ServerAddr;
    SOCKADDR_IN ClientAddr;
    int ClientAddrLen;
    int ServerPort = 59000;
    char ReceiveBuffer[10] = "0";
	char ReceiveBuffer2[10] = "0";
	//char Serverip[20] = "192.168.0.3";
    int Result;
    int ReceiveLen=1;

	cout << "#·þÎñ¶ËÆô¶¯#" << endl;

    if ((Result = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
    {
        cout<<"WSAStartup failed with error "<<Result<<endl;
        return;
    }
    ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ServerSocket < 0)
    {
        cout<<"socket failed with error"<<endl;
		WSACleanup();
        return ;
    }
    memset(&ServerAddr, 0, sizeof(ServerAddr));
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(ServerPort);
    ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	//ServerAddr.sin_addr.s_addr = inet_addr(Serverip);
    Result = bind(ServerSocket, (SOCKADDR*) &ServerAddr, sizeof(ServerAddr));
    if (Result < 0)
    {
		cout<<"Result is"<<Result<<endl;
        cout<<"bind failed with error"<<endl;
		WSACleanup();
        return ;
    }
    Result = listen(ServerSocket, 5);
    if (Result == SOCKET_ERROR)
    {
        printf("listen failed with error %d\n", WSAGetLastError());
        return ;
    }
    ClientAddrLen = sizeof(SOCKADDR);
    int SendLength;
    //do
    //{
        NewSocket = accept(ServerSocket, (SOCKADDR*) &ClientAddr, &ClientAddrLen);
        if (NewSocket < 0)
        {
            printf("accept failed with error %d\n", WSAGetLastError());
            return ;
        }
        //else
        //if (ReceiveLen != 0)
        //{
		// 	recv(NewSocket, ReceiveBuffer, 10, 0);
		//	printf( "%s\n", ReceiveBuffer );
        //}
		int len = recv(NewSocket, ReceiveBuffer, 10, 0);
		if(len != 0)
		{
			printf( "%s\n", ReceiveBuffer );
		}//Reload file name:

		char reloadfile[20] = "Reload file name:";
		send(NewSocket,reloadfile,strlen(reloadfile),0);
		cout<<"Send data is:"<<reloadfile<<endl;
		int len2 = recv(NewSocket,ReceiveBuffer2,10,0);
		cout<<"recv data is:"<<ReceiveBuffer2<<endl;

		server_process(ReceiveBuffer,ReceiveBuffer2);
		printf("Receive end\n");

        if (closesocket(NewSocket) == SOCKET_ERROR)
        {
            printf("closesocket failed with error %d\n", WSAGetLastError());
        };
    //}
    //while (1);

}
