#include "../minishell.h"

void	ft_echo(char **args)
{
	int		i;

	i = 1;
	if (ft_strncmp(args[1], "-n", 2) == 0)
		i++;
	while (args[i])
	{
		printf("%s", args[i]);
		i++;
		if (args[i])
			printf(" ");
	}
	if (ft_strncmp(args[1], "-n", 2))
		printf("\n");
}
