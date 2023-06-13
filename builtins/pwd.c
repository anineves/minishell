/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:04:32 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/13 11:04:33 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit_status;

void ft_pwd(t_global *global)
{
	char	pwd[PATH_MAX];

	if (getcwd(pwd, PATH_MAX) == NULL)
	{
		g_exit_status = 1;
		return ;
	}
	ft_putstr_fd(pwd, global->fd_output);
	ft_putchar_fd('\n', global->fd_output);
	g_exit_status = 0;
}
