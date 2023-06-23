/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:04:14 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/22 20:00:10 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit_status;

void ft_one_arg(t_global *global)
{
	int i;
	
	i = 0;
	g_exit_status = 0;
	ft_putstr_fd("exit\n", global->fd_output);
	if (global->args[1])
	{
		g_exit_status = ft_atoi(global->args[1]);
		g_exit_status = g_exit_status % 256;
		while(global->args[1][i] == '+' \
			|| global->args[1][i] == '-')
			i++;
		if (!ft_isdigit(global->args[1][i]))
		{
			printf("bash: exit: %s :numeric argument required\n",\
				global->args[1]);
			g_exit_status = 2;
		}
	}
	free_global(global);
	exit(g_exit_status);
}

void	ft_exit(t_global *global)
{
	int	i;
	
	i = 0;
	if (global->args[1] == NULL || (global->args[1] \
		&& (global->args[2] == NULL)))
		ft_one_arg(global);
	else
	{
		while(global->args[1][i])
		{
			if(ft_isalpha(global->args[1][i]))
			{
				printf("bash: exit: %s : numeric argument required\n", \
				global->args[1]);
				g_exit_status = 2;
				free_global(global);
				exit(g_exit_status);	
			}
			i++;
		}
		printf("exit\nbash: exit: too many arguments\n");
		g_exit_status = 1;
	}
}
