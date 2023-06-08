#include "../minishell.h"

extern int	g_exit_status;

void	ft_env(t_global *global)
{
	int	i;

	i = 0;
	if (global->args[1])
	{
		printf("env: '%s': No such file or directory\n", global->args[1]);
		g_exit_status = 127;
		return ;
	}
	global->len_env = size_env(global->copy_env);
	while (i < global->len_env)
	{
		printf("%s\n", global->copy_env[i]);
		i++;
	}
	g_exit_status = 0;
}
