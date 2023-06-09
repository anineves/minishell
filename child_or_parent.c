/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_or_parent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:04:44 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/14 20:28:02 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	is_child_builtin(t_global *global)
{
	if (global->args[0] != NULL)
	{
		if (ft_strcmp(global->args[0], "echo") == 0)
			return (1);
		else if (ft_strcmp(global->args[0], "pwd") == 0)
			return (1);
		else if (ft_strcmp(global->args[0], "export") == 0 && !global->args[1])
			return (1);
		else if (ft_strcmp(global->args[0], "env") == 0)
			return (1);
	}
	return (0);
}

void	execute_child_builtin(t_global *global)
{
	if (ft_strcmp(global->args[0], "echo") == 0)
		ft_echo(global);
	else if (ft_strcmp(global->args[0], "pwd") == 0)
		ft_pwd(global);
	else if (ft_strcmp(global->args[0], "export") == 0)
		ft_export(global);
	else if (ft_strcmp(global->args[0], "env") == 0)
		ft_env(global);
}

void	execute_parent_builtin(t_global *global)
{
	if (ft_strcmp(global->args[0], "exit") == 0)
		ft_exit(global);
	else if (ft_strcmp(global->args[0], "cd") == 0)
		ft_cd(global);
	else if (ft_strcmp(global->args[0], "export") == 0 \
		&& global->args[1] && global->shell->flag != PIPE)
		ft_export(global);
	else if (ft_strcmp(global->args[0], "unset") == 0)
		ft_unset(global);
}

int	is_parent_builtin(t_global *global)
{
	if (global->args[0] != NULL)
	{
		if (ft_strcmp(global->args[0], "exit") == 0)
			return (1);
		else if (ft_strcmp(global->args[0], "cd") == 0)
			return (1);
		else if (ft_strcmp(global->args[0], "export") == 0 \
			&& global->args[1] && global->shell->flag != PIPE)
			return (1);
		else if (ft_strcmp(global->args[0], "unset") == 0)
			return (1);
	}
	return (0);
}
