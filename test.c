
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
# include <fcntl.h>
#include "libft/libft.h"

int main(int argc, char *argv[])
{
	int fd;

	fd = open(argv[1], O_WRONLY | O_TRUNC);
	write(fd, "123asjdfh45", 5);
	close(fd);
}