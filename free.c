#include "minishell.h"

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
}

void	free_global(t_global *global)
{
	if (global->shell != NULL)
		free_data(&global->shell);
	if (global->cwd != NULL)
		free(global->cwd);
	if (global->copy_env != NULL)
	{
		free_args(global->copy_env);
		free(global->copy_env);
	}
	if (global->args != NULL)
	{
		free_args(global->args);
		free(global->args);
	}
}
