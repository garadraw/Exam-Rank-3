//Passed Moulinette 05.07.2022


#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	int rd = 0;
	char c;
	char *buffer = malloc(101010);
	int i = 0;

	while((rd = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
	{
		buffer[i] = c;
		if (buffer[i] == '\n')
		{
			buffer[i + 1] = '\0';
			return (buffer);
		}
		i++;
	}
	if (rd == -1 || i == 0 || (!rd && !buffer[i - 1]))
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return(buffer);
}

int main()
{
	int fd;
	char *s;

	fd = open("myfile.txt", O_RDONLY);
	s = get_next_line(fd);
	while (s != NULL)
	{
		printf("%s", s);
		s = get_next_line(fd);
	}
	return (0);
}