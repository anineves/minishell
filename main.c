/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:06:29 by mimoreir          #+#    #+#             */
/*   Updated: 2023/06/13 15:55:38 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

void	ft_exit2(t_global *global)
{
	free_global(global);
	free(global);
	printf("exit\n");
	exit(g_exit_status);
}

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	(void)argc;
	t_global	*global;
	char	*input;
	char	*real_input;

	global = init_global(env);
	while (1)
	{
		init_signals();
		input = readline("prompt% ");
		if (input == NULL)
		{
			//global->args = NULL;
			ft_exit2(global);
		}
		add_history(input);
		if (verify_input(input))
		{
			real_input = ft_expander(global, input);
			create_data(&global->shell, real_input);
			free(real_input);
			execute(global);
		}
		if(global->shell)
			free_data(&global->shell);
		free(input);
	}
	return (0);
}
