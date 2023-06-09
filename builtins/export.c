/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:04:20 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/13 23:50:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit_status;

void	ft_quotes(char *str, t_global *global)
{
	int	i;
	int	equal;

	i = 0;
	equal = 0;
	while (str[i])
	{
		if (str[i] == '=' && equal == 0)
		{
			equal = 1;
			ft_putchar_fd(str[i], global->fd_output);
			ft_putchar_fd('"', global->fd_output);
		}
		else
			ft_putchar_fd(str[i], global->fd_output);
		i++;
	}
	ft_putchar_fd('"', global->fd_output);
}

void	ft_sort(t_global *global)
{
	int		sort;
	int		i;
	char	*tmp;

	sort = 0;
	i = 0;
	while (!sort)
	{
		sort = 1;
		i = 0;
		while (global->copy_env[i + 1] != NULL)
		{
			if (ft_strcmp(global->copy_env[i], global->copy_env[i + 1]) > 0)
			{
				tmp = global->copy_env[i];
				global->copy_env[i] = global->copy_env[i + 1];
				global->copy_env[i + 1] = tmp;
				sort = 0;
			}
			i++;
		}
	}
}

void	verific_equal(char *copy_env, t_global *global)
{
	int	i;
	int	equal;

	i = 0;
	equal = 0;
	while (copy_env[i])
	{
		if (copy_env[i] == '=')
			equal = 1;
		i++;
	}
	if (equal == 1)
		ft_quotes(copy_env, global);
	else
		ft_putstr_fd(copy_env, global->fd_output);
	ft_putchar_fd('\n', global->fd_output);
}

void	ft_export(t_global *global)
{
	int	i;

	i = 0;
	if (global->args[1] == NULL)
	{
		ft_sort(global);
		while (global->copy_env[i])
		{
			ft_putstr_fd("declare -x ", 1);
			verific_equal(global->copy_env[i], global);
			i++;
		}
		g_exit_status = 0;
	}
	else
		create_new_var(global);
}
