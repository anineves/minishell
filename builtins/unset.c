#include "../minishell.h"

extern int	g_exit_status;

char	**rmv_var(t_global *global, int j,  int size)
{
	int			i;
	char		**new_copy_env;

	i = 0;
	printf("entrei rm");
	new_copy_env = ft_calloc(size + 1 , sizeof(char *));
	while (i < j)
	{
		new_copy_env[i] = ft_strdup(global->copy_env[i]);
		i++;
	}
	while (global->copy_env[i + 1] )
	{
		new_copy_env[i] = ft_strdup(global->copy_env[i + 1]);
		i++;
	}
	new_copy_env[i] = NULL;
	if (global->copy_env != NULL)
	{
		free_args(global->copy_env);
		//free(global->copy_env);
	}
	return (new_copy_env);
}


void ft_unset(t_global *global)
{
	int 	i;
	int	len;
	int	j;
	int k;
	int size;
	
	i = 1;
	len = 0;
	j = 0;
	k = 0;

	size = size_env(global->copy_env); 
	if(!global->args[i])
	{
		g_exit_status = 0;
		return	;
	}
	else
	{	
		while(global->args[i])
		{
			len = ft_strlen(global->args[i]);
			while(global->args[i][k] && global->args[i][k] != '=')
				k++;
			while(global->copy_env[j])	
			{
				printf("tamanho %d pos %d %s\n", size, j, global->copy_env[j]);
				if(!ft_strncmp(global->args[i], global->copy_env[j], len))
					global->copy_env = rmv_var(global, j, (size_env(global->copy_env) - 1));
				else if(!ft_strncmp(global->args[i], global->copy_env[j], k))
					global->copy_env = rmv_var(global, j, (size_env(global->copy_env) - 1));
				j++;
			}
			k=0;
			j=0;
			i++;
		}
	}
}
