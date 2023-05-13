/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <mimoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:06:29 by mimoreir          #+#    #+#             */
/*   Updated: 2023/05/13 15:17:27 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	(void)argc;
	(void)env;
	t_data	*shell;

	shell = malloc(sizeof(t_data*));
	init_signals();
	while (1)
	{
		shell->cmd = readline("prompt% ");
		if (shell->cmd == NULL)
		{
			free(shell->cmd);
			ft_printf("exit\n");
			free(shell);
			return (0);
		}

		ft_printf("%s\n", shell->cmd);
		add_history(shell->cmd);
		free(shell->cmd);
	}
	free(shell);
	return (0);
}

