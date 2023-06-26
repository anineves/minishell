/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:03:55 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/26 14:30:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit_status;

/*void	print_for_echo(char *str)
{
	char	*new;
	char	*it;
	char	*it2;

	new = ft_strdup(str);
	it = new;
	it2 = new;
	if (*it == '"' || *it == '\'')
	{
		it++;
		while (*it2)
			it2++;
		while (*it2 == '"' || *it2 == '\'')
			it2--;
		while (it != it2)
		{
			printf("%c", *it);
			it++;
		}
	}
	else
		while (*it)
		{
			printf("%c", *it);
			it++;
		}
	free(new);
}*/

bool	is_n(t_global *global)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(global->args[1]);
	while (global->args[1][i] == 'n' && global->args[1][i])
		i++;
	if (i == len)
		return (1);
	else
		return (0);
}

static int	size_arg(t_global *global)
{
	int	i;

	i = 0;
	while (global->args[i])
		i++;
	if (global->shell->flag == HEREDOC || global->shell->flag == RD_IN)
		i--;
	return (i);
}

void	ft_echo(t_global *global)
{
	int	i;
	int	len;

	i = 1;
	len = size_arg(global);
	if (!global->args[i])
	{
		ft_putstr_fd("\n", global->fd_output);
		return ;
	}
	if (ft_strncmp(global->args[1], "-n", 2) == 0 && is_n(global))
		i++;
	while (i < len && ft_strncmp(global->args[i], "-n", 2) == 0)
		i++;
	while (i < len)
	{
		printf("%s", global->args[i]);
		i++;
		if (global->args[i])
			printf(" ");
	}
	if (ft_strncmp(global->args[1], "-n", 2) != 0)
		printf("\n");
	g_exit_status = 0;
}
