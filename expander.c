#include "minishell.h"

extern int	g_exit_status;

char *is_env(t_global *global, char *temp)
{
	int len;
	int i;
	char *value;
	char *it;

	i =0;
	len = ft_strlen(temp);
	value = NULL;
	while (global->copy_env[i])
	{
		if (ft_strncmp(temp, global->copy_env[i], len) == 0 && global->copy_env[i][len] == '=')
		{
			it = global->copy_env[i];
			while (*it != '=')
				it++;
			it++;
			value = ft_strdup(it);
			break;
		}
		i++;
	}
	if(value == NULL)
		value = ft_strdup(" ");
	return (value);
}

char	*ft_charjoin(char *s1, char c)
{
	char	*new;
	char	*it;
	char	*it2;

	new = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!new)
		return (NULL);
	it = s1;
	it2 = new;
	while(*it)
	{
		*it2 = *it;
		it++;
		it2++; 
	}
	*it2++ = c;
	*it2 = '\0';
	return (new);
}

char	*ft_expander(t_global *global, char *input)
{
	char	*new;
	char	*it;
	char	*tmp;
	char	*num;
	char	*aux;
	int		squote;
	int		i;

	it = input;
	squote = 0;
	i = 0;
	new = ft_calloc(sizeof(char), 1);
	while (*it)
	{
		if(*it == '\'')
			squote = !squote;
		if(*it == '$' && squote == 0)
		{
			it++;
			if(*it == '?')
			{
				it++;
				num = ft_itoa(g_exit_status);
				tmp = ft_strjoin(new, num);
				free(new);
				free(num);
				new = tmp;
			}
			else
			{
				tmp = it;
				while (*it != ' ' && *it)
					it++;
				num = copy_len(tmp, it - tmp);
				aux = is_env(global, num);
				tmp = ft_strjoin(new, aux);
				free(num);
				free(new);
				free(aux);
				new = tmp;
			}
		}
		else
		{
			tmp = ft_charjoin(new, *it);
			free(new);
			new = tmp;
			it++;
		}
	}
	return (new);
}

/*void	ft_expan(t_global *global, char *input)
{
	int i;
	int j;
	int k;
	int len;
	int squote;
	char *temp;
	char *value;
	char *aux;
	char *new;
	
	i = 0;
	j = 0;
	k = 0;
	squote = 0;
	len = ft_strlen(input);
	value = NULL;
	temp = NULL;
	while (i < len)
	{
		if(input[i] == '\'')
			squote = !squote;
			
		if(input[i] == '$' && squote == 0)
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
				k = i;
				while(input[i] != ' ' && input[i])
					i++;
				temp = ft_substr(input, k, i);
				value = is_env(global, temp);
				len = ft_strlen(value);
				ft_memcpy(&input[j], value, len); //echo  user 
				j += len;						  //echo ansoua-n
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
*/