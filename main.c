#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

char	*get_next_line(int fd);

int main(void)
{
	int fd = open("test", O_RDONLY);
	for (int i = 0 ; i < 5 ; ++i)
	{
		printf("===========\n");
		printf("%s", get_next_line(fd));
	}
	close(fd);
	return (0);
}