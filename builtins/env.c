/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:04:06 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/13 11:04:08 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit_status;

void	ft_env(t_global *global)
{
	int	i;

	i = 0;
	if (global->args[1])
	{
		printf("env: '%s': No such file or directory\n", global->args[1]);
		g_exit_status = 127;
		return ;
	}
	global->len_env = size_env(global->copy_env);
	while (i < global->len_env)
	{
		printf("%s\n", global->copy_env[i]);
		i++;
	}
	g_exit_status = 0;
}
