#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h> /* pour exit */
#include <strings.h> /* pour bcopy */
#include <errno.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>
#include <string.h>

#include "cryptage.h"
#include "clean.h"

#define DEST_IP "127.0.0.1" 
#define DEST_PORT 50000
#define NMAX 6

int socket_RV;

void signals_handler(int signal_number)
{
    printf("Signal catched.\n");
    close(socket_RV);
    exit(EXIT_SUCCESS);
}

int init_socket(char *address, int port){
	struct sockaddr_in adr;
	if ((socket_RV=socket(AF_INET, SOCK_STREAM, 0)) ==-1)
	{
		perror("Socket Rendez-vous");
		return -1;
	}
	struct hostent *hote=gethostbyname(address);
	adr.sin_family=AF_INET;
	adr.sin_port=htons(port);
	bcopy(hote->h_addr, &adr.sin_addr.s_addr, hote->h_length);
	if ((connect(socket_RV, (struct sockaddr *)&adr, sizeof(adr)))==-1)
	{
		perror("Connect");
		return -2;
	}
	return 0;
}

int main(int argc,char * argv[])
{
	// -------------------------------------------
	// signals handler
	// -------------------------------------------
    struct sigaction action;
    action.sa_handler = signals_handler;
    sigemptyset(& (action.sa_mask));
    action.sa_flags = 0;
    sigaction(SIGINT, & action, NULL);

	// -------------------------------------------
	// Argument parser
	// -------------------------------------------
	if (argc==1) argv[1] = "127.0.0.1";
	char * address = argv[1];

	// -------------------------------------------
	// Client initialization
	// -------------------------------------------
	if(init_socket(address, DEST_PORT) != 0)
		exit(1);

	// -------------------------------------------
	// Client loop
	// -------------------------------------------
	char buffer[NMAX];
	char msg[NMAX];
	while (strncmp(msg,"quit",4))
	{
		// Clearing msg
		for(int i = 0; i < NMAX; ++i) msg[i] = '\0';
		for(int i = 0; i < NMAX; ++i) buffer[i] = '\0';

		printf("Input message (quit to exit):");
		fgets (buffer, NMAX, stdin);
		printf("Message length: %lu\n", strlen(buffer));

		if(transString(buffer, msg) == 1)
			printf("Your message needed to be cleaned (removed uppercase, space, nexline, etc...)\n because morse does not contain those characters\n");

		char* cry;
		if(msg[strlen(msg)-1] == '\n'){
			printf("1\n");
			msg[strlen(msg)-1] = '\0';
			cry = cryptage(msg);
			cry[strlen(msg)] = '\0';
		}
		else{
			printf("2\n");
			cry = cryptage(msg);
			cry[strlen(msg)] = '\0';
		}

		printf("Cryptage: %s\n", cry);
		if(-1 == write(socket_RV,cry,strlen(cry)))
		{
			printf("Write fail!\r\n");  
			return -1; 
		}

	}

	close(socket_RV);
	return 0;  
}
