#include "../minishell.h"

void	ft_sort(t_global *global)
{
	int		sort;
	int		i;
	char	*tmp;

	sort = 0;
	i = 0;
	while (!sort)
	{
		sort = 1;
		i = 0;
		while (global->copy_env[i + 1 ] != NULL)
		{
			if (ft_strcmp(global->copy_env[i], global->copy_env[i + 1]) > 0)
			{
				tmp = global->copy_env[i];
				global->copy_env[i] = global->copy_env[i + 1];
				global->copy_env[i + 1] = tmp;
				sort = 0;
			}
			i++;
		}
	}
}

void ft_export(t_global *global)
{
	int i;
	
	i = 0;
	if(global->args[1] == NULL)
	{
		ft_sort(global);
		while (global->copy_env[i])
		{
			ft_putstr_fd("declare -x ", 1);
				ft_putstr_fd(global->copy_env[i], global->fd_output);
				i++;
			ft_putchar_fd('\n', global->fd_output);
		}
	}
	//apenas se nao tiver argumentos
}
