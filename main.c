/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <mimoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:06:29 by mimoreir          #+#    #+#             */
/*   Updated: 2023/05/13 18:14:29 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

t_data	*init_data(void)
{
	t_data	*shell;

	shell = malloc(sizeof(t_data));
	if (!shell)
		return (NULL);
	shell->input = NULL;
	shell->spl_in = NULL;
	return (shell);
}

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	(void)argc;
	(void)env;
	t_data	*shell;

	shell = init_data();
	init_signals();
	while (1)
	{
		shell->input = readline("prompt% ");
		if (shell->input == NULL)
		{
			free(shell->input);
			ft_printf("exit\n"); //substituir por uma funcao de exit
			free(shell);
			return (0);
		}
		if (!(verify_input(shell) == 2))
		{
			ft_printf("%s\n", shell->input);
		}
		add_history(shell->input);
		free(shell->input);
	}
	free(shell);
	return (0);
}

