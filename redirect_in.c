#include "minishell.h"

extern int	g_exit_status;

/*
void red_in_heredoc(t_global *global)
{
	int		fd;

	fd = open(name, O_RDONLY | O_CLOEXEC, 0666);
	if (fd == -1)
	{
		printf("prompt: no such file or directory: gfd\n");
		exit(127);
	}
	return (fd);
}

void ft_heredoc(t_global *global)
{
	char	*rl;

	global->fd_heredoc = open("heredoc.tmp", O_CREAT | O_TRUNC | O_RDWR| 0644);
	while (true)
	{
		rl = readline("> ");
		if (ft_strcmp(rl, global->shell->next->cmd) )
		{
			ft_putstr_fd(rl, global->fd_heredoc);
			ft_putstr_fd("\n", global->fd_heredoc);
			
		}
		else
			break ;
		free(rl);
	}
}
*/

void red_in_heredoc(t_global *global)
{
    char *buf;

    if (global->shell->flag == RD_IN)
        global->fd_input = open(global->shell->next->cmd, O_RDONLY);
    else if (global->shell->flag == HEREDOC)
        global->fd_input = open(".here_doc", O_CREAT | O_WRONLY | O_RDWR, 0666);

    if (global->shell->flag == HEREDOC)
    {
        while (1)
        {
            buf = readline("> ");
            if (buf == NULL)
                break;
            if (strcmp(buf, global->shell->next->cmd) == 0)
            {
                free(buf);
                break;
            }
            write(global->fd_input, buf, strlen(buf));
            write(global->fd_input, "\n", 1);
            free(buf);
        }
        close(global->fd_input);
        global->fd_input = open(".here_doc", O_RDONLY);
    }
}


