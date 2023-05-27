/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <mimoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:06:29 by mimoreir          #+#    #+#             */
/*   Updated: 2023/05/27 13:48:37 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

/*void	free_data(t_data *shell)
{
	//depois tens de alterar por causa da lista
	free(shell->cmd);
	free(shell);
}*/

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
			//free_data(shell);
			return (0);
		}
		add_history(input);
		if (!(verify_input(&global->shell, input) == 2))
		{
			t_data *i;
	i = global->shell;
	while (i != NULL)
	{
		//rmvQuotes(shell->cmd);
		ft_printf("----------------\ncmd: %s\nflag:%d\n-------------\n", i->cmd, i->flag);
		i = i->next;
	}
		}
		free(input);
	}
	free(global);
	return (0);
}

