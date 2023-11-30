#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

int	main(int argc, char const *argv[])
{
	int		fd;
	char	readd[1024];

	fd = open("./test.txt", O_RDONLY);
	read(fd, readd, 1024);
	printf("%s\n", readd);
	// printf("%s fin \n", get_next_line(fd));
	// printf("%s fin \n", get_next_line(fd));
}
