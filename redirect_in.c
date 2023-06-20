/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:31:53 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/21 00:14:10 by marvin           ###   ########.fr       */
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
		rmv_quotes(global->shell->next->cmd);
		if (ft_strncmp(buf, global->shell->next->cmd, ft_strlen(buf)) == 0)
		{
			free(buf);
			break ;
		}
		write(global->fd_heredoc, buf, ft_strlen(buf));
		write(global->fd_heredoc, "\n", 1);
		free(buf);
	}
}

void	red_in_heredoc(t_global *global)
{
	char	*name;

	name = ft_strtrim(global->shell->next->cmd, " ");
	if (global->args[0] == NULL)
		global->flag = 1;
	if (global->shell->flag == RD_IN)
	{
		global->fd_input = open(name, O_RDWR);
		if (global->fd_input < 0)
		{
			printf("%s : No such file or directory\n", global->shell->next->cmd);
			exit(EXIT_FAILURE);
		}
	}
	else if (global->shell->flag == HEREDOC)
	{
		global->fd_heredoc = open("here_doc", O_CREAT | O_TRUNC | O_RDWR, 0644);
		ft_heredoc(global);
		global->fd_heredoc = open("here_doc", O_RDWR | 0644);
		global->fd_input = global->fd_heredoc;
	}
	if (global->shell->cmd)
		global->shell = go_to_next(global);
	if (global->shell->flag == RD_IN || global->shell->flag == HEREDOC)
		red_in_heredoc(global);
	free(name);
}
