/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:04:14 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/13 11:04:15 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit_status;

void ft_exit(t_global *global)
{
	if(global->args[1] == NULL || (global->args[1] && (global->args[2] == NULL)))
	{
		g_exit_status = 0;
		ft_putstr_fd("exit\n", global->fd_output);
		if(global->args[1])
		{
			if(!ft_isdigit(global->args[1][0]))
				printf("bash: exit: %s : numeric argument required\n", global->args[1]);
		}
		free_global(global);
		exit(g_exit_status);
	}
	else
	{
		printf("exit\nbash: exit: too many arguments\n");
		g_exit_status = 0;
	}

}
