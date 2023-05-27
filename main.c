/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <mimoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:06:29 by mimoreir          #+#    #+#             */
/*   Updated: 2023/05/27 15:50:00 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

void	free_data(t_data **shell)
{
	t_data	*it;

	it = (*shell);
	while (it != NULL)
	{
		it = it->next;
		free((*shell)->cmd);
		free(*shell);
		(*shell) = it;
	}
}

void	free_global(t_global *global)
{
	if (global->shell != NULL)
		free_data(&global->shell);
	if (global->cwd != NULL)
		free(global->cwd);
	if (global->copy_env != NULL)
		free(global->copy_env);
	if (global->args != NULL)
		free(global->args);
}

size_t	size_env(char **env)
{
	size_t		len;
	int		i;

	i = 0;
	len = 0;
	while (env[i])
	{
		len+= ft_strlen(env[i]);
		i++;
	}
	return (len + i);
}


int	init_env(t_global *global, char **env)
{
	int		i;
	size_t		len;
	
	i = 0;
	len = 0;
	len = size_env(env);
	global->len_env = len;
	global->copy_env = malloc(sizeof(char *) * (len + 1));
	if (!global->copy_env)
		return (0);
	i = 0;
	while (env[i])
	{
		global->copy_env[i] = ft_strdup(env[i]);
		if (!global->copy_env[i])
			return (0);
		i++;
	}
	return (1);
}

t_global	*init_global(char **env)
{
	t_global	*new;

	new = (t_global*)malloc(sizeof(t_global));
	if (!new)
		return (NULL);
	if(!init_env(new, env))	
		return (0);
	new->shell = NULL;
	new->cwd = getcwd(NULL, 4096);
	new->old_path = getenv("HOME");
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
			//ft_printf("%s\n", global->shell->cmd);
		}
		free(input);
		free_data(&global->shell);
	}
	free_global(global);
	return (0);
}
