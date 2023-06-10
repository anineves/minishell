#include "minishell.h"

void ft_close(t_global *global)
{
	if (global->fd_input != STDIN_FILENO)
		close(global->fd_input);
	else if (global->fd_output != STDOUT_FILENO)
		close(global->fd_output);
}

t_data	*go_to_next(t_global *global)
{
	t_data *aux;
	aux = global->shell->next;
	free(global->shell->cmd);
	free(global->shell);
	return (aux);
}

void	free_data(t_data **shell)
{
	t_data	*it;

	it = (*shell);
	while (it != NULL)
	{
		it = it->next;
		free((*shell)->cmd);
		free(*shell);
		(*shell) = it;
	}
}

void	free_args(char	**args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	free_global(t_global *global)
{
	if (global->shell != NULL)
		free_data(&global->shell);
	if (global->cwd != NULL)
		free(global->cwd);
	if (global->args != NULL)
		free_args(global->args);
	if (global->path != NULL)
		free(global->path);
	if (global->split_path != NULL)
		free_args(global->split_path);
	if (global->copy_env != NULL)
		free_args(global->copy_env);
}
