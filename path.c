/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:15:01 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/23 23:02:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*absolute_path(char *arg, t_global *global)
{
	char	*tmp;
	char	*cmd;
	int		i;

	if (global->path)
		free(global->path);
	global->path = get_path(global->copy_env, global->path);
	if (global->path == NULL)
		return (NULL);
	if (global->split_path)
		free_args(global->split_path);
	global->split_path = ft_split(global->path, ':');
	if (access(arg, F_OK) == 0)
		return (cmd = ft_strdup(arg));
	i = -1;
	while (global->split_path[++i])
	{
		tmp = ft_strjoin(global->split_path[i], "/");
		cmd = ft_strjoin(tmp, arg);
		free(tmp);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		free(cmd);
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

	if (!global->args[0])
		return (NULL);
	if (arg[0] == '/')
		path = relative_path(arg, global);
	else
		path = absolute_path(arg, global);
	return (path);
}
