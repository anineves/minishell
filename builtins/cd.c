#include "../minishell.h"

extern int	g_exit_status;

void change_dir(t_global *global, char *next_path)
{
	char *path;
		
	path = getcwd(NULL, 0);
	global->old_path = ft_strdup(path);
	if (chdir(next_path) == 0 )
			g_exit_status = 0;
	else
	{
		printf("bash: cd: %s: No such file or directory\n", global->args[1]);
		g_exit_status = 1;
	}
	free(path);
}

void ft_cd(t_global *global)
{
	char *next_path;
	
	next_path = NULL;
	if(global->args[1] && global->args[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", global->fd_output);
		g_exit_status = 1;		
		return ;
	}
	if( global->args[1] )
	{
		if((ft_strcmp(global->args[1], "-") == 0))
		{
			ft_putstr_fd(global->old_path, global->fd_output);
			ft_putstr_fd("\n", global->fd_output);
			g_exit_status = 0;
			return ;
		}
	}
	next_path = global->args[1];
	if((!global->args[1]) || (ft_strcmp(global->args[1], "~") == 0) || (ft_strncmp(global->args[1], "--", 3) == 0))
		next_path = getenv("HOME");
	change_dir(global, next_path);
}
