#include "minishell.h"

extern int	g_exit_status;

void	open_pipes(t_global *global, int *pipe_fd)
{
	if ((global->shell->next != NULL && global->shell->next->flag) || (global->shell->next != NULL \
		&& (global->shell->flag != HEREDOC && global->shell->flag != RD_IN)))
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

void	wait_and_exit_status()
{
    while (waitpid(0, (int *)&g_exit_status, WEXITSTATUS(g_exit_status)) > 0)
        continue;
    if (!WTERMSIG(g_exit_status))
        g_exit_status = WEXITSTATUS(g_exit_status);
}
