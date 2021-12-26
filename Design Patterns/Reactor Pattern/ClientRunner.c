#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define PORT 7000

/*
A client connects to the server and attempts to send some diagnostic information (text)
*/

int main(int argc, char const *argv[])
{
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char buffer[1024] = {0};
    time_t t;
    srand((unsigned) time(&t));

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary form
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}

	char *diagnostics = "Some diagnostics from client";
    int i = 0;
	while (i < 5)
	{
		send(sock, diagnostics, strlen(diagnostics), 0);
		printf("Diagnostics sent\n");
        int randTime = rand() % 6;
        printf("Sleeping for %d seconds.\n", randTime);
        sleep(randTime);
        i++;
	}

	printf("Client exiting\n");

	return 0;
}