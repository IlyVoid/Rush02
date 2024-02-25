#include "Rush02.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*find_num(int fd)
{
	int	    i;
	char	c[1];
	char	*str;

	if (!(str = malloc(sizeof(char) * 128)))
		exit(1);
	i = 0;
	read(fd, c, 1);
	while (c[0] == '\n')
		read(fd, c, 1);
	while (c[0] >= '0' && c[0] <= '9')
	{
		str[i] = c[0];
		read(fd, c, 1);
		i++;
	}
	return (str);
}

char	*find_val(int fd, char *c)
{
	int	    i;
	char	*str;

	if (!(str = malloc(sizeof(char) * 128)))
		exit(1);
	i = 0;
	while (c[0] != '\n')
	{
		str[i] = c[0];
		read(fd, c, 1);
		i++;
	}
	return (str);
}

t_list	*operate(char *file)
{
	int	    i;
	int	    fd;
	char	c[1];
	t_list	*tab;
	char    *temp;

	fd = open(file, O_RDONLY);
	if (fd == -1 || !(tab = malloc(sizeof(t_list) * 33)))
		exit(1);
	i = 0;
	while (i < 32)
	{
		tab[i].n = atoi_num(find_num(fd));
		read(fd, c, 1);
		while (c[0] == ' ')
			read(fd, c, 1);
		if (c[0] == ':')
			read(fd, c, 1);
		while (c[0] == ' ')
			read(fd, c, 1);
		temp = find_val(fd, c);
		tab[i].val = str_dup(temp);
		free(temp);
		i++;
	}
	close(fd);
	return (tab);
}
