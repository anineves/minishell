#include "../minishell.h"

extern int	g_exit_status;

void	ft_env(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->len_env)
	{
		printf("%s\n", global->copy_env[i]);
		i++;
	}
	g_exit_status = 0;
}
