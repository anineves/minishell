/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:06:29 by mimoreir          #+#    #+#             */
/*   Updated: 2023/06/17 16:53:36 by asousa-n         ###   ########.fr       */
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
	t_global	*global;
	char		*input;
	char		*real_input;

	(void)argv;
	(void)argc;
	global = init_global(env);
	while (1)
	{
		init_signals();
		input = readline("prompt% ");
		if (input == NULL)
			ft_exit2(global);
		add_history(input);
		if (verify_input(input))
		{
			real_input = ft_expander(global, input, NULL);
			create_data(&global->shell, real_input, 0, NULL);
			free(real_input);
			execute(global);
		}
		free_data(&global->shell);
		free(input);
	}
	return (0);
}
