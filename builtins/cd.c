#include "../minishell.h"

extern int	g_exit_status;

void ft_cd(t_data *shell)
{
	char *path;
	char *next_path;

	if(shell->args[1] && shell->args[2])
	{
		printf("minishell: cd: too many arguments\n");
		g_exit_status = 1;		
		return ;
	}
	if(!shell->args[1] || (ft_strcmp(shell->args[1], "~") == 0))
		next_path = getenv("HOME");
	path = getcwd(NULL, 0);
	shell->old_path = ft_strdup(path);
	if (chdir(next_path) == 0 )
	{
		g_exit_status = 0;
	}
	else
	{
		printf("bash: cd: %s: No such file or directory", shell->args[1]);
		g_exit_status = 1;
	}
	free(path);

}
