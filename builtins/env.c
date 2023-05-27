#include "../minishell.h"

extern int	g_exit_status;

void	ft_env(t_data *shell)
{
	int	i;

	i = 0;
	while (i < shell->len_env)
	{
		printf("%s\n", shell->copy_env[i]);
		i++;
	}
	g_exit_status = 0;
}
