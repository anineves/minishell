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

t_global	*init_global(void)
{
	t_global	*new;

	new = (t_global*)malloc(sizeof(t_global));
	if (!new)
		return (NULL);

	new->shell = NULL;
	new->cwd = getcwd(NULL, 4096);
	new->old_path = getenv("HOME");
	new->len_env = 0;
	new->copy_env = NULL;
	return (new);
}

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	(void)argc;
	(void)env;
	t_global	*global;
	char	*input;

	global = init_global();
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
