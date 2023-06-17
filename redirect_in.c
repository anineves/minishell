/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:31:53 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/17 11:27:58 by asousa-n         ###   ########.fr       */
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
	if (global->args[0] == NULL)
		global->flag = 1;
	if (global->shell->flag == RD_IN)
		global->fd_input = open(global->shell->next->cmd, O_RDWR, 0644);
	else if (global->shell->flag == HEREDOC)
	{
		global->fd_input = open("here_doc", O_CREAT | O_TRUNC | O_RDWR, 0644);
		ft_heredoc(global);
	}
	/*if (!ft_strncmp(global->shell->cmd, "cat", 3) || !ft_strncmp(global->shell->cmd, "wc", 2))
	{
		free_args(global->args);
		if (global->shell->flag == HEREDOC)
			tmp = ft_strjoin(global->shell->cmd, " here_doc");
		else
		{
			tmp = ft_strjoin(global->shell->cmd, " ");
			//if (!ft_str)
			tmp = ft_strjoin(global->shell->cmd, global->shell->next->cmd);
		}
		global->args = ft_split2(tmp, ' ');
	} */
	if (global->shell->cmd)
		global->shell = go_to_next(global);
	free(tmp);
}
