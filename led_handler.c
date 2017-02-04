#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>

#include "morse.h"
#include "handleLED.h"

#define NMAX 6

// Pipe file descriptor
int fd;

void signals_handler(int signal_number)
{
    printf("Signal catched.\n");
   	close(fd);
	
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
	// -------------------------------------------
	// signals handler
	// -------------------------------------------
    struct sigaction action;
    action.sa_handler = signals_handler;
    sigemptyset(& (action.sa_mask));
    action.sa_flags = 0;
    sigaction(SIGINT, & action, NULL);

	int led = open("/sys/class/gpio/gpio21/value", O_WRONLY);
	
	char buffer[NMAX];
	char * pipe = "svr2led";

	// Open file desciptor
	fd = open(pipe, O_RDONLY);
	printf("Pipe opened.\n");

	while (strncmp(buffer,"txlw",4))
	{
		// Clear buffer
		for(int i=0; i<NMAX; ++i) buffer[i] = '\0';

		// Write message
		read(fd, buffer, NMAX);

		// Print buffer
		printf("%s\n", buffer);

		// Blink led
		int morse = stringToMorse(buffer);
		readMorse(&morse, 1, led);
	}

	// Close output pipe
	close(fd);

	return EXIT_SUCCESS;
}
