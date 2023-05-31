#include "minishell.h"

void	redirection(t_global *global)
{
	if (global->shell->flag == APPEND)
		append_to_file(global);
	if (global->shell->flag == RD_OUT)
		write_to_file(global);
}

void	append_to_file(t_global *global)
{
	int	fd;

	fd = open(global->shell->next->cmd, O_APPEND | O_CREAT | O_RDWR);
	if (fd < 0)
	{
		printf("ERROR WITH FILE\n");
		return ;
	}
	ft_putstr_fd(global->shell->cmd, fd);
	close(fd);
}

void	write_to_file(t_global *global)
{
	int	fd;

	fd = open(global->shell->next->cmd, O_CREAT | O_RDWR);
	if (fd < 0)
	{
		printf("ERROR WITH FILE\n");
		return ;
	}
	ft_putstr_fd(global->shell->cmd, fd);
	close(fd);
}
