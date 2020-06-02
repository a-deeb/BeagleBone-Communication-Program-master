#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <windows.networking.sockets.h>			/* Include Winsock libraries */
#pragma comment(lib, "Ws2_32.lib")				/* Link Winsock DLLs */
#include <iostream>	

static bool ExeComplete = false;

enum SocketType { CLIENT, SERVER };
enum ConnectionType { TCP, UDP };
const int DEFAULT_SIZE = 100;

class MySocket {
	char *Buffer;
	SOCKET WelcomeSocket;
	SOCKET ConnectionSocket;
	struct sockaddr_in SvrAddr;
	SocketType mySocket;
	std::string IPAddr;
	int port;
	ConnectionType connectionType;
	bool bTCPConnect;
	int MaxSize;

	bool connectSocket(SOCKET&, int, int);

public:
	MySocket(SocketType, std::string, unsigned int, ConnectionType, unsigned int size = DEFAULT_SIZE);
	~MySocket();
	void SendData(const char*, int);
	int GetData(char*);
	std::string GetIPAddr();
	void SetIPAddr(std::string);
	void setPort(unsigned int);
	int getPort();
	SocketType GetType();
	void SetType(SocketType);
	void ConnectTCP();
	void DisconnectTCP();
};

#endif