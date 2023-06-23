/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:04:06 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/23 22:31:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit_status;

int	ft_aux_env(char *env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

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
		if (ft_aux_env(global->copy_env[i]))
			printf("%s\n", global->copy_env[i]);
		i++;
	}
	g_exit_status = 0;
}
