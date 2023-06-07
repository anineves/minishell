#include "minishell.h"

extern int	g_exit_status;

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


