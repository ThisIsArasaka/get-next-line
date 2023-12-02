#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

int	main(int argc, char const *argv[])
{
	int		fd;
	//char	readd[1024];

	fd = open("./test.txt", O_RDONLY);
	//read(fd, readd, 1024);
	//printf("%s\n %d \n %c", readd, (int)ft_strlen(readd), readd[71]);
	printf("%s|\n", get_next_line(fd));
	printf("%s|\n", get_next_line(fd));
	printf("%s|\n", get_next_line(fd));
	printf("%s|\n", get_next_line(fd));
}
