#include "../minishell.h"


void	ft_echo(t_global *global)
{
	int		i;
	i = 1;
	
	if(!global->args[i])
		return ;
	if (ft_strcmp(global->args[1], "-n") == 0)
		i++;
	while (global->args[i])
	{
		printf("%s", global->args[i]);
		i++;
		if (global->args[i])
			printf(" ");
	}
	if (ft_strcmp(global->args[1], "-n") != 0)
		printf("\n");
}
