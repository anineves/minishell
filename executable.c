#include "minishell.h"

char	*absolute_path(char *arg, t_global *global)
{
	char	*tmp;
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	if (arg[0] == '\0')
		return (NULL);
	while (global->split_path[i])
	{
		tmp = ft_strjoin(global->split_path[i], "/");
		path = ft_strjoin(tmp, arg);
		free(tmp);
		if (access(path, F_OK) == 0)
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
	path = ft_strjoin(tmp, arg);
	free(tmp);
	if (access(path, F_OK) == 0)
		return (path);
	free(path);
	if (access(arg, F_OK) == 0)
		return (ft_strdup(arg));
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
}

void ft_executable(t_global *global)
{
	char		*path;
	int	p;

	p = fork();
	path = get_type_path(global->args[0], global);
	if (p == 0)
	{
		if (path)
		{
			execve(path, global->args, global->copy_env);
		}
		else
		{
			printf("Minishell: command not found: %s\n", global->args[0]);
		}
		exit(1);
	}
	wait(NULL);
}
