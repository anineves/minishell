#include "../minishell.h"

extern int	g_exit_status;

void	print_for_echo(char *str)
{
	char	*new;
	char	*it;
	char	*it2;

	new = ft_strdup(str);
	it = new;
	it2 = new;
	if (*it == '"' || *it == '\'')
	{
		it++;
		while (*it2)
			it2++;
		while (*it2 == '"' || *it2 == '\'')
			it2--;
		while (it != it2)
		{
			printf("%c", *it);
			it++;
		}
	}
	else
		while (*it)
		{
			printf("%c", *it);
			it++;
		}
	free(new);
}

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
		//printf("%s",global->args[i]);
		if(ft_strcmp(global->args[i], "$?") == 0)
			ft_putstr_fd(ft_itoa(g_exit_status), global->fd_output);
		else	
			print_for_echo(global->args[i]);
		i++;
		if (global->args[i])
			printf(" ");
	}
	if (ft_strcmp(global->args[1], "-n") != 0)
		printf("\n");
}
