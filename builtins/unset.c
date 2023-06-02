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
	int k;
	
	i = 1;
	len = 0;
	j = 0;
	k = 0;
	if(!global->args[1])
		g_exit_status = 0;
	else
	{
		while(global->args[i])
		{
			len = ft_strlen(global->args[i]);
			while(global->args[i][k] && global->args[i][k] != '=')
				k++;
			while(global->copy_env[j])	
			{
				if(!ft_strncmp(global->args[i], global->copy_env[j], len))
					rmv_var(global, j);
				else if(!ft_strncmp(global->args[i], global->copy_env[j], k))
					rmv_var(global, j);
				j++;
			}
			j=0;
			i++;
			free(global->args[i]);
		}
	}
}
