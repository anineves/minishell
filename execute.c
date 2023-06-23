/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:30:50 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/21 00:29:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

static int	aux_execute(t_global *global, char *path, int *pipe_fd)
{
	close(pipe_fd[WRITE_END]);
	while (global->shell != NULL)
	{
		if (global->shell->flag == PIPE)
		{
			execute_next_shell(global, path, pipe_fd);
			return (1);
		}
		else if (global->shell->flag == RD_OUT \
			|| global->shell->flag == APPEND)
			red_out_append(global, pipe_fd[READ_END]);
		global->shell = go_to_next(global);
	}
	return (0);
}

void	handle_child_process(t_global *global, char *path, int pipe_fd[])
{
	if (global->shell->flag == RD_IN || global->shell->flag == HEREDOC)
		red_in_heredoc(global);
	if (path || is_child_builtin(global))
		open_pipes(global, pipe_fd);
	if (is_child_builtin(global))
		execute_child_builtin(global);
	else if (!path && !is_parent_builtin(global))
	{
		if (global->flag == 1)
			unlink("here_doc");
		if (global->args[0] != NULL && global->flag == 0)
		{
			if (ft_strcmp(global->args[0], "export") != 0)
			{
				printf("Minishell: command not found: %s\n", global->args[0]);
				g_exit_status = 127;
				exit(127);
			}
		}
	}
	else if (path && !is_child_builtin(global))
		execve(path, global->args, global->copy_env);
	if (path != NULL)
		free(path);
	exit(g_exit_status);
}

void	child_process(t_global *global, char *path, int pipe_fd[])
{
	init_child_signals();
	wait_and_exit_status();
	handle_child_process(global, path, pipe_fd);
}

void	execute_next_shell(t_global *global, char *path, int pipe_fd[2])
{
	if (global->shell->next->flag == HEREDOC \
		|| global->shell->next->flag == RD_IN)
		wait_and_exit_status();
	global->shell = go_to_next(global);
	free_args(global->args);
	global->fd_input = pipe_fd[READ_END];
	if (path != NULL)
		free(path);
	execute(global);
}

void	execute(t_global *global)
{
	char	*path;
	int		pipe_fd[2];
	static int	num_pipe = 0;

	global->args = ft_split2(global->shell->cmd, ' ');
	pipe(pipe_fd);
	path = get_type_path(global->args[0], global);
	if (global->shell->flag == PIPE)
		num_pipe = 1;
	init_child_signals();
	if (fork() == 0)
		handle_child_process(global, path, pipe_fd);
	else
	{
		if (is_parent_builtin(global) && global->shell->flag != PIPE && num_pipe != 1)
			execute_parent_builtin(global);
		else if (global->shell->next != NULL)
		{
			if (aux_execute(global, path, pipe_fd))
				return ;
		}
		else
			ft_close(global);
		wait_and_exit_status();
	}
	final_exec(global, path);
	num_pipe = 0;
}
