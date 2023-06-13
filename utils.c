/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:32:20 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/14 00:31:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	switch_quotes(char s, int *indquotes, int *insquotes)
{
	if (s == '"' && !(*insquotes))
		*indquotes = !(*indquotes);
	if (s == '\'' && !(*indquotes))
		*insquotes = !(*insquotes);
}

char	*copy_len(char *src, size_t len)
{
	char	*it;
	char	*new;
	size_t	i;

	i = 0;
	new = malloc(sizeof(char) * (len + 1));
	it = new;
	while (i < len)
	{
		*it = *src;
		it++;
		src++;
		i++;
	}
	*it = '\0';
	return (new);
}

int	verify_quotes(char c)
{
	static int	count = 0;
	static char	quotes = '\0';

	if ((c == '"' || c == '\'') && quotes == '\0')
	{
		count++;
		quotes = c;
	}
	else if (quotes != '\0' && (c == '"' || c == '\''))
	{
		if (quotes == c)
		{
			count = 0;
			quotes = '\0';
		}
	}
	return (count);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
		i++;
	return (str1[i] - str2[i]);
}
