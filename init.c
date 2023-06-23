/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:31:21 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/23 22:25:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path(char **copy_env, char *path)
{
	int	i;

	i = 0;
	while (copy_env[i])
	{
		if (!ft_strncmp(copy_env[i], "PATH", 4))
		{
			path = ft_strdup(copy_env[i]);
			return (path);
		}
		i++;
	}
	return (NULL);
}

size_t	size_env(char **env)
{
	size_t	len;

	len = 0;
	while (env[len])
	{
		len++;
	}
	return (len);
}

char	**init_env(char **env)
{
	int			i;
	size_t		len;
	char		**copy_env;

	i = 0;
	len = size_env(env);
	copy_env = malloc(sizeof(char *) * (len + 3));
	if (!copy_env)
		return (0);
	while (env[i])
	{
		copy_env[i] = ft_strdup(env[i]);
		i++;
	}
	copy_env[i] = NULL;
	return (copy_env);
}

t_global	*init_global(char **env)
{
	t_global	*new;

	new = (t_global *)malloc(sizeof(t_global));
	if (!new)
		return (NULL);
	new->shell = NULL;
	new->cwd = getcwd(NULL, 4096);
	new->old_path = ft_strdup("bash: cd: OLDPWD not set; \n");
	new->copy_env = init_env(env);
	new->len_env = size_env(env);
	new->args = NULL;
	new->fd_input = 0;
	new->fd_output = 1;
	new->flag = 0;
	new->path = get_path(new->copy_env, new->path);
	new->split_path = ft_split(new->path, ':');
	return (new);
}
