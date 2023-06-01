#include "../minishell.h"

extern int	g_exit_status;

void	rmv_var(t_global *global, int j)
{
	int i;
	
	i = j;
	while(global->copy_env[i])
	{
		global->copy_env[i] = global->copy_env[i + 1];
		i++;
	}
	global->copy_env[i] = NULL;

}


void ft_unset(t_global *global)
{
	int 	i;
	int	len;
	int	j;
	
	i = 1;
	len = 0;
	j = 0;
	
	if(!global->args[1])
		g_exit_status = 0;
	else
	{
		while(global->args[i])
		{
			len = ft_strlen(global->args[i]);
			while(global->copy_env[j])	
			{
				if(!ft_strncmp(global->args[i], global->copy_env[j], len))
					rmv_var(global, j);
				j++;
			}
			i++;
			free(global->args[i]);
		}
	}
}
