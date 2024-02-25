#ifndef RUSH02_H
# define RUSH02_H

typedef struct	s_list
{
	int	    n;
	char    *val;
}		t_list;
int	atoi_num(const char *str);
char	*str_dup(char *src);
void	put_str(char *str);
char	*find_num(int fd);
char	*find_val(int fd, char *c);
t_list	*operate(char *file);

#endif
