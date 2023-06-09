#include "minishell.h"

extern int	g_exit_status;

char *is_env(t_global *global, char *temp)
{
	int len;
	int i;
	//int = j;
	char *value;

	i =0;
	//j = 0;
	len = ft_strlen(temp);
	value = NULL;
	while (global->copy_env[i])
	{
		
		if (ft_strncmp(temp, global->copy_env[i], len) == 0 && global->copy_env[i][len] == '=')
		{
			value = ft_strdup(global->copy_env[i] + len + 1);
			//free(global->copy_env[i]);
			break;
		}
		i++;
	}
	if(value == NULL)
		value = ft_strdup(" ");
	return value;
}

void ft_expander(t_global *global, char *input)
{
	int i;
	int j;
	int k;
	int len;
	char temp[20];
	char *value;
	char *aux;
	
	
	i = 0;
	j = 0;
	k = 0;
	len = ft_strlen(input);
	while (i < len)
	{
		
		if(input[i] == '$' )
		{
			i++;
			if(input[i] == '?')
			{
				aux = ft_itoa(g_exit_status);
				len = ft_strlen(aux);
				ft_memcpy(&input[j], aux, len);
				j += len;
				free(aux);
					
			}
			else
			{
				while(input[i] != ' ' && input[i])
				{
					temp[k] = input[i];
					k++;
					i++;
				}
				temp[k] = '\0';
				value = ft_strdup(is_env(global, temp));
				len = ft_strlen(value);
				ft_memcpy(&input[j], value, len);
				j += len;
				free(value);
			}
		}
		else
		{
			input[j++] = input[i];
		}
		len = ft_strlen(input);
		i++;
	}
	input[j] = '\0';
}
