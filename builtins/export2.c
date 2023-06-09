#include "../minishell.h"

extern int	g_exit_status;

char	**init_env2(char **copy_env, t_global *global, int size)
{
	int			i;
	char		**new_copy_env;

	i = 0;
	new_copy_env = ft_calloc(size + 1 , sizeof(char *));
	while (copy_env[i])
	{
		new_copy_env[i] = ft_strdup(copy_env[i]);
		i++;
	}
	new_copy_env[i] = NULL;
	new_copy_env[i + 1] = NULL;
	free_args(global->copy_env);
	return (new_copy_env);
}


void create_new_var(t_global *global)
{
	int size;
	int i;
	
	i=1;
	ft_unset(global);
	while(global->args[i])
	{		
		if(ft_isalpha(global->args[i][0]))
		{
			size = size_env(global->copy_env);
			global->copy_env = init_env2(global->copy_env, global, (size + 1));
			global->copy_env[size] = ft_strdup(global->args[i]);
			i++;
			g_exit_status = 0;
		}
		else
		{
			printf("bash: export: %s: not a valid identifier\n", global->args[i]);
			g_exit_status = 1;
			return ;
		}
	}
}
