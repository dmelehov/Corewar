#include "../includes/vm.h"

bool	is_flag(char *av)
{
	char *flags;

	flags = "adsvbn";
	if (*av != '-' || ft_strlen(av) != 2)
		return (false);
	av++;
	while (*flags)
		if (*av == *flags++)
			return (true);
	return (false);
}

int 	flag_attr(char *av)
{
	if (av[1] == 'd' || av[1] == 's' || av[1] == 'v')
		return (1);
	return (0);
}
