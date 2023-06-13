/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:31:53 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/14 00:22:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

void	ft_heredoc(t_global *global)
{
	char	*buf;

	buf = NULL;
	while (1)
	{
		buf = readline("> ");
		if (buf == NULL)
			break ;
		if (ft_strncmp(buf, global->shell->next->cmd, ft_strlen(buf)) == 0)
		{
			free(buf);
			break ;
		}
		write(global->fd_input, buf, ft_strlen(buf));
		write(global->fd_input, "\n", 1);
		free(buf);
	}
	close(global->fd_input);
}

void	red_in_heredoc(t_global *global)
{
	char	*tmp;

	tmp = NULL;
	if (global->shell->flag == RD_IN)
		global->fd_input = open(global->shell->next->cmd, O_RDWR, 0644);
	else if (global->shell->flag == HEREDOC)
	{
		global->fd_input = open("here_doc", O_CREAT | O_TRUNC | O_RDWR, 0644);
		ft_heredoc(global);
	}
	free_args(global->args);
	if (global->shell->flag == HEREDOC)
		tmp = ft_strjoin(global->shell->cmd, " here_doc");
	else
	{
		tmp = ft_strjoin(global->shell->cmd, " ");
		tmp = ft_strjoin(global->shell->cmd, global->shell->next->cmd);
	}
	global->args = ft_split2(tmp, ' ');
	if (global->shell->cmd)
		global->shell->cmd = global->shell->next->cmd;
	free(tmp);
}
