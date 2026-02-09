#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;

	if (fd == -1)
	{
		printf("Dosya acilamadi!\n");
		return (1);
	}
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
