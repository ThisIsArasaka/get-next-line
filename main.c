#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

int	main(void)
{
	int		fd;
	char *str;
	//char	readd[1024];

	fd = open("./gnlTester/files/nl", O_RDONLY);
	str = get_next_line(fd);
	//read(fd, readd, 1024);
	//printf("%s\n %d \n %c", readd, (int)ft_strlen(readd), readd[71]);
	printf("%s|\n", str);
	str = get_next_line(fd);
	printf("%s|\n", str);
	free(str);
	close(fd);
}
