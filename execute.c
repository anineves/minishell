#include "minishell.h"

extern int	g_exit_status;

int	is_child_builtin(t_global *global)
{
	if (ft_strcmp(global->args[0], "echo") == 0)
		return (1);
	else if (ft_strcmp(global->args[0], "pwd") == 0)
		return (1);
	else if (ft_strcmp(global->args[0], "env") == 0)
		return (1);
	return (0);
}

void	execute_child_builtin(t_global *global)
{
	if (ft_strcmp(global->args[0], "echo") == 0)
		ft_echo(global);
	else if (ft_strcmp(global->args[0], "pwd") == 0)
		ft_pwd(global);
	else if (ft_strcmp(global->args[0], "env") == 0)
		ft_env(global);
}

void	is_parent_builtin(t_global *global)
{
	if (ft_strcmp(global->args[0], "exit") == 0)
		ft_exit(global);
	else if (ft_strcmp(global->args[0], "cd") == 0)
		ft_cd(global);
	else if (ft_strcmp(global->args[0], "export") == 0 && global->args[1] && global->shell->flag != PIPE)
		ft_export(global);
	else if (ft_strcmp(global->args[0], "unset") == 0)
		ft_unset(global);
}

/*void builtin parent (export sem argumentos pertence ao filho)*/
/*echo ola | ls
void	execute(t_global *global) //talvez aqui seja melhor por a receber um fd para mandar junto
{
	while (true)
	{
		if (!global->shell->cmd)
			break ;
		if (global->shell->flag != EMPTY)
			redirection(global);
		//else if (global->shell->next->flag == PIPE)

		else
			execute_no_redirection(global);
	}
}
*/
