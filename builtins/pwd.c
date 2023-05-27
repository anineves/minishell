#include "../minishell.h"

extern int	g_exit_status;

void ft_pwd()
{
	char	pwd[PATH_MAX];

	if (getcwd(pwd, PATH_MAX) == NULL)
	{
		g_exit_status = 1;
		return ;
	}
	printf("%s\n", pwd);
	g_exit_status = 0;
}
