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

#define DEST_IP "127.0.0.1" 
#define DEST_PORT 50303
#define NMAX 100

int main(int argc,char * argv[])
{
	if (argc==1) argv[1]="127.0.0.1";
	int socket_RV;
	int sin_size; 
	int pid; 
	char *buffer;
	buffer=malloc(sizeof(char)*NMAX);
	struct sockaddr_in adr;
	if ((socket_RV=socket(AF_INET, SOCK_STREAM, 0)) ==-1)
	{
		perror("Socket Rendez-vous");
		exit(1);
	}
	struct hostent *hote=gethostbyname(argv[1]);
	adr.sin_family=AF_INET;
	adr.sin_port=htons(DEST_PORT);
	bcopy(hote->h_addr, &adr.sin_addr.s_addr, hote->h_length);
	if ((connect(socket_RV, (struct sockaddr *)&adr, sizeof(adr)))==-1)
	{
		perror("Connect");
		exit(1);
	}
	char msg[NMAX];
	char *cry;
	
	while (strncmp(msg,"quit",4))
	{
		printf("Input message:");
		fgets (msg, NMAX, stdin);

		cry = cryptage(msg);

		printf("%s\n", cry);


		if(-1 == write(socket_RV,msg,NMAX))  
		{
			printf("Write fail!\r\n");  
			return -1; 
		}    
	}

	close(socket_RV);
	return 0;  
}
