#include "Rush02.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	find_tens(int nb)
{
	if (nb >= 90)
		return (90);
	else if (nb >= 80)
		return (80);
	else if (nb >= 70)
		return (70);
	else if (nb >= 60)
		return (60);
	else if (nb >= 50)
		return (50);
	else if (nb >= 40)
		return (40);
	else if (nb >= 30)
		return (30);
	else if (nb >= 20)
		return (20);
	else if (nb <= 20)
		return (nb);
	else
		return (0);
}

int	find_multi(int nb)
{
	if (nb >= 1000000000)
		return (1000000000);
	else if (nb >= 1000000)
		return (1000000);
	else if (nb >= 1000)
		return (1000);
	else if (nb >= 100)
		return (100);
	else
		return (find_tens(nb));
}

void	print(int n, t_list *tab, int *first)
{
	int i;
	int multi;

	i = 0;
	multi = find_multi(n);
	if (multi >= 100)
		print(n / multi, tab, first);
	if (*first == 0)
		write(1, " ", 1);
	*first = 0;
	while (tab[i].n != multi)
		i++;
	put_str(tab[i].val);
	if (multi != 0 && n % multi != 0)
		print(n % multi, tab, first);
}

int	main(int ac, char **av)
{
	t_list *tab;
	int     *first;
	int     add_first;

	add_first = 1;
	first = &add_first;
	if (ac == 2)
	{
		if (atoi_num(av[1]) < 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		tab = operate("en_dict.txt");
		print(atoi_num(av[1]), tab, first);
	}
	return (0);
}
