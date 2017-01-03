#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_BUF 1024

int main(int argc, char *argv[])
{
	char buf[MAX_BUF];
	char * pipe = "svr2cry";

	// Open file desciptor
	int fd = open(pipe, O_RDONLY);

	// Write message
	read(fd, buf, MAX_BUF);

	// Print buffer
	printf("%s\n", buf);

	// Close output pipe
	close(fd);

	return EXIT_SUCCESS;
}