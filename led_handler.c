#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define NMAX 100

int main(int argc, char *argv[])
{

	

	
	char buffer[NMAX];
	char * pipe = "svr2led";

	// Open file desciptor
	int fd = open(pipe, O_RDONLY);

	printf("Pipe opened.\n");

	while (strncmp(buffer,"quit",4))
	{
		// Write message
		read(fd, buffer, NMAX);

		// Print buffer
		printf("%s\n", buffer);

		// Clear buffer
		for(int i=0; i<NMAX; ++i)
			buffer[i] = '\0';
	}

	// Close output pipe
	close(fd);

	return EXIT_SUCCESS;
}