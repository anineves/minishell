/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:22:21 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/17 14:22:23 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

char	*is_env(t_global *global, char *temp)
{
	int		len;
	int		i;
	char	*value;
	char	*it;

	i = 0;
	len = ft_strlen(temp);
	value = NULL;
	while (global->copy_env[i])
	{
		if (ft_strncmp(temp, global->copy_env[i], len) == 0 \
			&& global->copy_env[i][len] == '=')
		{
			it = global->copy_env[i];
			while (*it != '=')
				it++;
			it++;
			value = ft_strdup(it);
			break ;
		}
		i++;
	}
	if (value == NULL)
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
	while (*it)
	{
		*it2 = *it;
		it++;
		it2++;
	}
	*it2++ = c;
	*it2 = '\0';
	return (new);
}
