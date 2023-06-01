#include "minishell.h"

extern int	g_exit_status;

char	*get_path2(char *arg, t_global *global)
{
	char	*tmp;
	char	*cmd;
	int		i;

	if (access(arg, F_OK) == 0 )
	{
		cmd = ft_strdup(arg);
		return (cmd);
	}
	i = 0;
	while (global->split_path[i])
	{
		tmp = ft_strjoin(global->split_path[i], "/");
		cmd = ft_strjoin(tmp, arg);
		free(tmp);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	return (NULL);
}

/*
char	*absolute_path(char *arg, t_global *global)
{
	char	*tmp;
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (global->split_path[i])
	{
		tmp = ft_strjoin(global->split_path[i], "/");
		path = ft_strjoin(tmp, arg);
		free(tmp);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	*relative_path(char *arg, t_global *global)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin(global->cwd, "/");
	path = ft_strjoin(tmp, arg + 2);
	free(tmp);
	if (access(path, X_OK) == 0)
		return (path);
	free(path);
	return (NULL);
}

char	*get_type_path(char *arg, t_global *global)
{
	char	*path;

	if (arg[0] == '.')
		path = relative_path(arg, global);
	else
		path = absolute_path(arg, global);
	return (path);
} */


void ft_executable(t_global *global)
{
	char	*path;
	int		p;

	p = fork();
	path = get_path2(global->args[0], global);
	if (p == 0)
	{
		if (path)
		{
			if ( execve(path, global->args, global->copy_env) < 0)
			{	
				free(path);
				g_exit_status = 1;
			}
		}
		else
		{
			printf("Minishell: command not found: %s\n", global->args[0]);
			g_exit_status = 127;
	
		}
		exit(1);
	}
	free(path);
	wait(NULL);
}
