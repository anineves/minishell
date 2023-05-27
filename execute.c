#include "minishell.h"

void execute(t_global *global)
{
	if (!global->shell->cmd == NULL)
		return ;
	if (ft_strncmp(global->shell->cmd, "echo ", 5) == 0)
		ft_echo(shell->args);
	else if (ft_strcmp(shell->args[0], "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(shell->args[0], "env") == 0)
		ft_env(shell);
	else if (ft_strcmp(shell->args[0], "exit") == 0)
		ft_exit(shell);
	else if (ft_strcmp(shell->args[0], "cd") == 0)
		ft_cd(shell);
	else(


	return;
}
