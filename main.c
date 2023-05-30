/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:06:29 by mimoreir          #+#    #+#             */
/*   Updated: 2023/05/29 21:50:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

char	*get_path(char **copy_env, char *path)
{
	int	i;

	i = 0;
	while (copy_env[i])
	{
		if (!ft_strncmp(copy_env[i], "PATH", 4))
		{
			path = copy_env[i];
			return (path);
		}
		i++;
	}
	return (NULL);
}

size_t	size_env(char **env)
{
	size_t		len;

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
	copy_env = malloc(sizeof(char*) * (len + 1));
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

	new = (t_global*)malloc(sizeof(t_global));
	if (!new)
		return (NULL);
	new->shell = NULL;
	new->cwd = getcwd(NULL, 4096);
	new->old_path = getenv("HOME");
	new->copy_env = init_env(env);
	new->len_env = size_env(env);
	new->args = NULL;
	new->fd_input = 0;
	new->fd_output = 1;
	new->path = get_path(new->copy_env, new->path);
	new->split_path = ft_split(new->path, ':');
	return (new);
}

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	(void)argc;
	t_global	*global;
	char	*input;

	global = init_global(env);
	init_signals();
	while (1)
	{
		input = readline("prompt% ");
		if (input == NULL)
		{
			free_global(global);
			free(global);
			return (0);
		}
		add_history(input);
		if (verify_input(input))
		{
			create_data(&global->shell, input);
			execute(global);
		}
		free(input);
		free_data(&global->shell);
		/*if (global->args)
			free_args(global->args);*/
	}
	free_global(global);
	return (0);
}
