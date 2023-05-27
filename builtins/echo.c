#include "../minishell.h"


void	ft_echo(char *args)
{
	int		i;
	char **arg;
	i = 1;

	rmvQuotes(args);
	arg = ft_split2(args, ' ');
	if (ft_strncmp(arg[1], "-n", 2) == 0)
		i++;
	while (arg[i])
	{
		printf("%s", arg[i]);
		i++;
		if (arg[i])
			printf(" ");
	}
	if (ft_strncmp(arg[1], "-n", 2))
		printf("\n");
}
