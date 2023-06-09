/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:16:48 by mimoreir          #+#    #+#             */
/*   Updated: 2023/06/23 22:55:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	nstrings(char const *s, char c, size_t i)
{
	size_t	n;
	int		indquotes;
	int		insquotes;

	n = 0;
	indquotes = 0;
	insquotes = 0;
	while (s && s[i])
	{
		switch_quotes(s[i], &indquotes, &insquotes);
		if (s[i] == c && !indquotes && !insquotes)
			i++;
		else if (s[i] != c)
		{
			n++;
			while (s[i] && s[i] != c)
			{
				switch_quotes(s[i], &indquotes, &insquotes);
				i++;
			}
		}
		else
			i++;
	}
	return (n);
}

static size_t	strsize(char const *s, char c)
{
	size_t	len;
	int		indquotes;
	int		insquotes;

	indquotes = 0;
	insquotes = 0;
	len = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s == '"' && !insquotes)
			indquotes = !indquotes;
		if (*s == '\'' && !indquotes)
			insquotes = !insquotes;
		if (*s == c && !indquotes && !insquotes)
			break ;
		s++;
		len++;
	}
	return (len);
}

void	copyword2(char const **s, char **tmp, int *indquotes, int *insquotes)
{
	if (((**s == '"') && !(*insquotes)) || ((**s == '\'') && !(*indquotes)))
		(*s)++;
	else
	{
		**tmp = **s;
		(*tmp)++;
		(*s)++;
	}
}

char	*copyword(char const *s, char c, size_t len)
{
	char	*str;
	char	*tmp;
	int		indquotes;
	int		insquotes;

	indquotes = 0;
	insquotes = 0;
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
		if (*s == c && !indquotes && !insquotes)
			break ;
		switch_quotes(*s, &indquotes, &insquotes);
		copyword2(&s, &tmp, &indquotes, &insquotes);
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
	nstr = nstrings(s, c, 0);
	arr = malloc(sizeof(char *) * (nstr + 1));
	if (!arr)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		strlen = strsize(s, c);
		arr[i++] = copyword(s, c, strlen);
		s += strlen;
	}
	arr[i] = NULL;
	return (arr);
}
