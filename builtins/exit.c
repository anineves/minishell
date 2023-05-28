#include "../minishell.h"

extern int	g_exit_status;

void ft_exit(t_global *global)
{
	if(global->args[1] == NULL)
	{
		g_exit_status = 0;
		free_global(global);
		exit(g_exit_status);
	}
	else if(global->args[1] && (global->args[2] == NULL))
	{
		g_exit_status = 0;
		free_global(global);
		exit(g_exit_status);
	}
	else
	{
		printf("exit\n bash: exit: too many arguments\n");
		g_exit_status = 1;
	}

}
