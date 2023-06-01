#include "minishell.h"

extern int	g_exit_status;

void	execute_no_redirection(t_global *global)
{
	global->args = ft_split2(global->shell->cmd, ' ');
	if (ft_strcmp(global->args[0], "echo") == 0)
		ft_echo(global);
	else if (ft_strcmp(global->args[0], "pwd") == 0)
		ft_pwd(global);
	else if (ft_strcmp(global->args[0], "env") == 0)
		ft_env(global);
	else if (ft_strcmp(global->args[0], "exit") == 0)
		ft_exit(global);
	else if (ft_strcmp(global->args[0], "cd") == 0)
		ft_cd(global);
	else if (ft_strcmp(global->args[0], "export") == 0)
		ft_export(global);
	else if (ft_strcmp(global->args[0], "unset") == 0)
		ft_unset(global);
	else
		ft_executable(global);
	free_args(global->args);
	free(global->args);
	return;
}

void	execute(t_global *global) //talvez aqui seja melhor por a receber um fd para mandar junto
{
	if (!global->shell->cmd)
		return ;
	if (global->shell->flag != EMPTY)
		redirection(global);
	else
		execute_no_redirection(global);
}
