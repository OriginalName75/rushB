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
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#include "cryptage.h"

#define MYPORT 50000
#define NMAX 6

int socket_service, socket_RV;
int pipe_fd;
char * pipe_name = "svr2led";

void signals_handler(int signal_number)
{
    printf("Signal catched.\n");
   
	close(pipe_fd);
	unlink(pipe_name);

	close(socket_service);
	close(socket_RV);

    exit(EXIT_SUCCESS);
}

int init_server(int port){
	int lgadresse;
	char nom[30]={0};
	struct sockaddr_in adr,adresse;
	if ((socket_RV=socket(AF_INET, SOCK_STREAM, 0)) ==-1)
	{
		perror("Socket Rendez-vous");
		return -1;
	}
	if (gethostname(nom, 30)==-1)
	{
		perror("Qui-suis je ?");
		return -1;
	}
	printf("Machine : %s\n", nom);
	adr.sin_family=AF_INET;
	adr.sin_port=htons(MYPORT);
	adr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(socket_RV, (struct sockaddr *) &adr, sizeof(adr))==-1)
	{
		perror("Bind");
		return -1;
	}
	if (listen(socket_RV,1)==-1)
	{
		perror("Listen");
		return -1;
	}
	lgadresse = sizeof(struct sockaddr_in);
	socket_service=accept(socket_RV, (struct sockaddr *)&adresse, &lgadresse);
	if(socket_service == -1)  
	{  
		printf("Accept fail !\r\n");  
		return -1;  
	}
	return 0;
}

int main()
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
	// Pipe init
	// -------------------------------------------
	if(mkfifo(pipe_name, 0644) != 0)
	{
		perror("mkfifo");
		return EXIT_FAILURE;
	}
	// Open file desciptor
	pipe_fd = open(pipe_name, O_WRONLY | O_CREAT);
	printf("Pipe opened.\n");

    // -------------------------------------------
	// Server init
	// -------------------------------------------
	if(init_server(MYPORT) != 0)
		exit(EXIT_FAILURE);

	// -------------------------------------------
	// Server loop (txlw is quit encrypted)
	// -------------------------------------------
	char buffer[NMAX];
	while (strncmp(buffer,"txlw",4))
	{
		// Clearing buffer
		for(int i = 0; i < NMAX; ++i) buffer[i] = '\0';

		if(-1 == read(socket_service,buffer,NMAX))  
		{  
			printf("Read fail !\r\n");  
			return -1;  
		}

		write(pipe_fd, buffer, strlen(buffer));
				
		// Print the decrypted message
		printf("%s\n",decryptage(buffer));
		fflush(stdout);
	}


	// Close output pipe
	close(pipe_fd);
	unlink(pipe_name);

	close(socket_service);
	close(socket_RV);  
	return 0; 
}
