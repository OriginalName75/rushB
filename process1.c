#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char * msg = "message test.";
	char * pipe = "svr2cry";

	if(mkfifo(pipe, 0644) != 0)
	{
		perror("mkfifo");
		return EXIT_FAILURE;
	}

	// Open file desciptor
	int fd = open(pipe, O_WRONLY);

	// Write message
	write(fd, msg, strlen(msg));

	// Close output pipe
	close(fd);

	// remove the pipe
	unlink(pipe);

	return EXIT_SUCCESS;
}