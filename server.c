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

int main()
{
	int socket_RV,socket_service;
	int lgadresse;
	int pid;
	char nom[30]={0};
	struct sockaddr_in adr,adresse;
	if ((socket_RV=socket(AF_INET, SOCK_STREAM, 0)) ==-1)
	{
		perror("Socket Rendez-vous");
		exit(1);
	}
	if (gethostname(nom, 30)==-1)
	{
		perror("Qui-suis je ?");
		exit(1);
	}
	printf("Machine : %s\n", nom);
	adr.sin_family=AF_INET;
	adr.sin_port=htons(MYPORT);
	adr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(socket_RV, (struct sockaddr *) &adr, sizeof(adr))==-1)
	{
		perror("Bind");
		exit(1);
	}
	if (listen(socket_RV,1)==-1)
	{
		perror("Listen");
		exit(1);
	}
	lgadresse = sizeof(struct sockaddr_in);
	socket_service=accept(socket_RV, (struct sockaddr *)&adresse, &lgadresse);
	if(socket_service == -1)  
	{  
		printf("Accept fail !\r\n");  
		return -1;  
	}
	char *msg;
	msg=malloc(sizeof(char)*NMAX);
	char *buffer;
	buffer=malloc(sizeof(char)*NMAX);

	// Pipe
	char * pipe = "svr2led";
	if(mkfifo(pipe, 0644) != 0)
	{
		perror("mkfifo");
		return EXIT_FAILURE;
	}
	// Open file desciptor
	int pipe_fd = open(pipe, O_WRONLY | O_CREAT);
	printf("Pipe opened.\n");

	while (strncmp(buffer,"txlw",4))
	{
		if(-1 == read(socket_service,buffer,NMAX))  
		{  
			printf("Read fail !\r\n");  
			return -1;  
		}

		write(pipe_fd, buffer, strlen(buffer));
		

		//buffer[strlen(buffer)-1] = '\0';		

		printf("%s\n",decryptage(buffer));
		fflush(stdout);
	}


	// Close output pipe
	close(pipe_fd);
	unlink(pipe);

	close(socket_service);
	close(socket_RV);  
	return 0; 
}
