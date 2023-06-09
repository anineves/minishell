#include "minishell.h"

extern int	g_exit_status;

char	*get_path2(char *arg, t_global *global)
{
	char	*tmp;
	char	*cmd;
	int		i;

	if (access(arg, F_OK) == 0 )
	{
		cmd = ft_strdup(arg);
		return (cmd);
	}
	i = 0;
	while (global->split_path[i])
	{
		tmp = ft_strjoin(global->split_path[i], "/");
		cmd = ft_strjoin(tmp, arg);
		free(tmp);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	return (NULL);
}

void	open_pipes(t_global *global, int *pipe_fd)
{
	if ((global->shell->next != NULL && global->shell->next->flag) || (global->shell->next != NULL && (global->shell->flag != HEREDOC && global->shell->flag != RD_IN)))
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

void child_process(t_global *global, char *path, int pipe_fd[])
{
	/*colocar uma funcao para lidar com o CTRL'C */
	signal(SIGINT, &ignore_signal);
	if (global->shell->flag == RD_IN || global->shell->flag == HEREDOC)
	{
		red_in_heredoc(global);
	}
	open_pipes(global, pipe_fd);
	if (path && !is_child_builtin(global))
		execve(path, global->args, global->copy_env);
	else if (is_child_builtin(global))
		execute_child_builtin(global);
	else if (!path && !is_parent_builtin(global))
	{
		printf("Minishell: command not found: %s\n", global->args[0]);
		g_exit_status = 127;
		exit(127);
	}
	free(path);
	exit(g_exit_status);/*retornar o exit status do child builtins*/
}


void execute(t_global *global)
{
	char *path;
	int pipe_fd[2];

	global->args = ft_split2(global->shell->cmd, ' ');
	pipe(pipe_fd);
	path = get_path2(global->args[0], global);
	if (fork() == 0)
		child_process(global, path, pipe_fd);
	else
	{
		waitpid(0, (int *)&g_exit_status, WEXITSTATUS(g_exit_status));
		if (!WTERMSIG(g_exit_status))
			g_exit_status = WEXITSTATUS(g_exit_status);
		if (is_parent_builtin(global) && global->shell->flag != PIPE)
			execute_parent_builtin(global);
		else if (global->shell->next != NULL)
		{
			close(pipe_fd[WRITE_END]);
			while (global->shell != NULL)
			{
				if (global->shell->flag == PIPE)
				{
					global->shell = go_to_next(global);
					free_args(global->args);
					global->fd_input = pipe_fd[READ_END];
					free(path);
					execute(global);
					return;
				}
				else if (global->shell->flag == RD_OUT || global->shell->flag == APPEND)
					red_out_append(global, pipe_fd[READ_END]);
				global->shell = go_to_next(global);
			}
		}
		else
			ft_close(global);
	}
	free(path);
	free_args(global->args);
}

