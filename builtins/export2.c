#include "../minishell.h"

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
	if (global->copy_env != NULL)
	{
		free_args(global->copy_env);
		free(global->copy_env);
	}
	return (new_copy_env);
}


void create_new_var(t_global *global)
{
	int size;
	int i;
	
	i=1;
	while(global->args[i])
	{
		ft_unset(global);
		if(ft_isalpha(global->args[i][0]))
		{
			size = size_env(global->copy_env);
			global->copy_env = init_env2(global->copy_env, global, (size + 1));
			global->copy_env[size] = ft_strdup(global->args[i]);
			i++;
		}
		else
		{
			printf("bash: export: %s: not a valid identifier\n", global->args[i]);
			return ;
		}
	}
	
	
}
