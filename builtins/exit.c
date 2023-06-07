#include "../minishell.h"

extern int	g_exit_status;

void ft_exit(t_global *global)
{
	if(global->args[1] == NULL || (global->args[1] && (global->args[2] == NULL)))
	{
		g_exit_status = 0;
		ft_putstr_fd("exit\n", global->fd_output);
		if(global->args[1])
		{
			if(!ft_isdigit(global->args[1][0]))
				printf("bash: exit: %s : numeric argument required", global->args[1]);
		}
		free_global(global);
		exit(g_exit_status);
	}
	else
	{
		printf("exit\nbash: exit: too many arguments\n");
		g_exit_status = 0;
	}

}
