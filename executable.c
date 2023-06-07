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

/*
char	*absolute_path(char *arg, t_global *global)
{
	char	*tmp;
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (global->split_path[i])
	{
		tmp = ft_strjoin(global->split_path[i], "/");
		path = ft_strjoin(tmp, arg);
		free(tmp);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	*relative_path(char *arg, t_global *global)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin(global->cwd, "/");
	path = ft_strjoin(tmp, arg + 2);
	free(tmp);
	if (access(path, X_OK) == 0)
		return (path);
	free(path);
	return (NULL);
}

char	*get_type_path(char *arg, t_global *global)
{
	char	*path;

	if (arg[0] == '.')
		path = relative_path(arg, global);
	else
		path = absolute_path(arg, global);
	return (path);
} */
/*ls | wc */
void	open_pipes(t_global *global, int *pipe_fd)
{
	/*se existir mais comandos escrever para o pipe_fd(write end)*/
	if (global->shell->next != NULL)
	{
		//printf("%s\n", global->shell->cmd);
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
                    red_in_heredoc(global);
	open_pipes(global, pipe_fd);
	if (path && !is_child_builtin(global))
		execve(path, global->args, global->copy_env);
	else if (is_child_builtin(global))
		execute_child_builtin(global);
	else if (!path && !is_parent_builtin(global))
	{
		printf("Minishell: command not found: %s\n", global->args[0]);
		exit(127);
	}

	free(path);
	
	exit(g_exit_status);/*retornar o exit status do child builtins*/
}

void ft_close(t_global *global)
{
	if (global->fd_input != STDIN_FILENO)
		close(global->fd_input);
	else if (global->fd_output != STDOUT_FILENO)
		close(global->fd_output);
}
/*child builtins (pwd, export (sozinho), echo)*/
void execute(t_global *global)
{
    char *path;
    int pipe_fd[2];

    pipe(pipe_fd);
    ft_expander(global, global->shell->cmd);
    global->args = ft_split2(global->shell->cmd, ' ');
    path = get_path2(global->args[0], global);
    if (fork() == 0)
        child_process(global, path, pipe_fd);
    else
    {
        waitpid(0, (int *)&g_exit_status, WEXITSTATUS(g_exit_status));
        if (!WTERMSIG(g_exit_status))
            g_exit_status = WEXITSTATUS(g_exit_status);
        printf("%d\n", g_exit_status);
        if (is_parent_builtin(global) && global->shell->flag != PIPE)
            execute_parent_builtin(global);
        else if (global->shell->next != NULL)
        {
            close(pipe_fd[WRITE_END]);
            while (global->shell != NULL)
            {
                if (global->shell->flag == PIPE)
                {
                    global->shell = global->shell->next;
                    global->fd_input = pipe_fd[READ_END];
                    execute(global);
                    return;
                }
                else if (global->shell->flag == RD_OUT || global->shell->flag == APPEND)
                    red_out_append(global, pipe_fd[READ_END]);
                global->shell = global->shell->next;
            }
        }
        else
            ft_close(global);
    }
    free(path);
    free_args(global->args);
}

