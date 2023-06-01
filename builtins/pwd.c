#include "../minishell.h"

extern int	g_exit_status;

void ft_pwd(t_global *global)
{
	char	pwd[PATH_MAX];

	if (getcwd(pwd, PATH_MAX) == NULL)
	{
		g_exit_status = 1;
		return ;
	}
	ft_putstr_fd(pwd, global->fd_output);
	ft_putchar_fd('\n', global->fd_output);
	g_exit_status = 0;
}
