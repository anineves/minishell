/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <mimoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:16:48 by mimoreir          #+#    #+#             */
/*   Updated: 2023/05/27 16:18:46 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdlib.h>

static size_t	nstrings(char const *s, char c)
{
	size_t	n;

	n = 0;
	while (*s && *s == c)
		s++;
	if (*s)
		n++;
	while (*s)
	{
		if (*s == c)
		{
			n++;
			while (*s && *s == c)
				s++;
			continue;
		}
		s++;
	}
	return (n);
}

static size_t	strsize(char const *s, char c)
{
	size_t	len;
	int		inQuotes = 0;

	len = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if ((*s == '"' || *s == '\'') && (*(s - 1) != '\\' || *(s - 2) == '\\'))
			inQuotes = !inQuotes;
		if (*s == c && !inQuotes)
			break;
		s++;
		len++;
	}
	return (len);
}

static char	*copyword(char const *s, char c, size_t len)
{
	char	*str;
	char	*tmp;
	int	inQuotes;
	
	inQuotes = 0;

	if (!*s)
		return (NULL);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	tmp = str;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if ((*s == '"' || *s == '\'') && (*(s - 1) != '\\' || (*(s - 1) == '\\' && *(s - 2) == '\\')))
			inQuotes = !inQuotes;
		if (*s == c && !inQuotes)
			break;
		*tmp = *s;
		tmp++;
		s++;
	}
	*tmp = '\0';
	return (str);
}

char	**ft_split2(char const *s, char c)
{
	char	**arr;
	size_t	nstr;
	size_t	strlen;
	size_t	i;

	i = 0;
	nstr = nstrings(s, c);
	arr = malloc(sizeof(char *) * (nstr + 1));
	if (!arr)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break;
		strlen = strsize(s, c);
		arr[i++] = copyword(s, c, strlen);
		s += strlen;
	}
	arr[i] = NULL;
	return (arr);
}

