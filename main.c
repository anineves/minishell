/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:06:29 by mimoreir          #+#    #+#             */
/*   Updated: 2023/06/08 13:20:33 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

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
		if (input == NULL )
		{
			free_global(global);
			free(global);
			return (0);
		}
		add_history(input);
		if (verify_input(global, input))
		{
			create_data(&global->shell, input);
			execute(global);
		}
		if(input)
			free(input);
		if(global->shell)
			free_data(&global->shell);
	}
	if (global->copy_env != NULL)
	{
		free_args(global->copy_env);
		free(global->copy_env);
	}
	free(global);
	return (0);
}
