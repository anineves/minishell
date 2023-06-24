/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:22:41 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/24 14:17:42 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

static void	aux_open_pipes(t_global *global, int *pipe_fd)
{
	close(pipe_fd[READ_END]);
	if (global->fd_input != STDIN_FILENO)
	{
		dup2(global->fd_input, STDIN_FILENO);
		close(global->fd_input);
	}
	dup2(pipe_fd[WRITE_END], STDOUT_FILENO);
	close(pipe_fd[WRITE_END]);
}

void	open_pipes(t_global *global, int *pipe_fd)
{
	if ((global->shell->next != NULL && global->shell->next->flag) \
		|| (global->shell->next != NULL \
		&& (global->shell->flag != HEREDOC && global->shell->flag != RD_IN)))
	{
		aux_open_pipes(global, pipe_fd);
	}
	else
	{
		if (global->fd_input != STDIN_FILENO)
		{
			dup2(global->fd_input, STDIN_FILENO);
			close(global->fd_input);
		}
		if (global->fd_output != STDOUT_FILENO)
		{
			dup2(global->fd_output, STDOUT_FILENO);
			close(global->fd_output);
		}
	}
}

void	wait_and_exit_status(void)
{
	while (waitpid(0, (int *)&g_exit_status, WEXITSTATUS(g_exit_status)) > 0)
		continue ;
	if (!WTERMSIG(g_exit_status))
		g_exit_status = WEXITSTATUS(g_exit_status);
	wait(NULL);
}

void	final_exec(t_global *global, char *path)
{
	if (path != NULL)
		free(path);
	unlink("here_doc");
	free_args(global->args);
	global->args = NULL;
}
