#include "../minishell.h"

extern int	g_exit_status;

void ft_exit(t_data *shell)
{
	if(shell->args[1] == NULL)
	{
		g_exit_status = 0;
		exit(g_exit_status);
	}
	else if(shell->args[1] && (shell->args[2] == NULL))
	{
		g_exit_status = 0;
		exit(g_exit_status);
	}
	else
	{
		printf("exit\n bash: exit: too many arguments\n");
		g_exit_status = 1;
			
	}
	
}
