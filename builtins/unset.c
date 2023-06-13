/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:04:38 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/13 23:54:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit_status;

char	**rmv_var(t_global *global, int j, int size)
{
	int		i;
	char	**new_copy_env;

	i = 0;
	new_copy_env = ft_calloc(size + 1, sizeof(char *));
	while (i < j)
	{
		new_copy_env[i] = ft_strdup(global->copy_env[i]);
		i++;
	}
	j++;
	while (global->copy_env[j])
	{
		new_copy_env[i] = ft_strdup(global->copy_env[j]);
		i++;
		j++;
	}
	new_copy_env[i] = NULL;
	free_args(global->copy_env);
	return (new_copy_env);
}

void	verific_var(t_global *global)
{
	int	i;
	int	len;
	int	j;
	int	k;

	i = 0;
	len = 0;
	j = 0;
	k = 0;
	while (global->args[i])
	{
		len = ft_strlen(global->args[i]);
		while (global->args[i][k] && global->args[i][k] != '=')
			k++;
		j = 0;
		while (global->copy_env[j])
		{
			if (!ft_strncmp(global->args[i], global->copy_env[j], len))
				global->copy_env = rmv_var(global, j, (size_env(global->copy_env) - 1));
			else if (!ft_strncmp(global->args[i], global->copy_env[j], k) && global->args[i][0] != '=')
				global->copy_env = rmv_var(global, j, (size_env(global->copy_env) - 1));
			else
				j++;
		}
		k = 0;
		i++;
	}
}

void	ft_unset(t_global *global)
{
	if (!global->args[1])
	{
		g_exit_status = 0;
		return ;
	}
	else
	{
		verific_var(global);
		g_exit_status = 0;
	}
}
