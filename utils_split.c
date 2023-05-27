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

static size_t	nstrings(char const *s, char c, int count)
{
	size_t	n;

	n = 0;
	while (*s && *s == c)
		s++;
	if (*s)
		n++;
	while (*s)
	{
		if (*s == c && count == 0)
		{
			count = verify_quotes(*s);
			n++;
			while (*s && *s == c)
				s++;
			continue ;
		}
		s++;
	}
	return (n);
}

static size_t	strsize(char const *s, char c, int count)
{
	size_t	len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c && count == 1)
	{
		count = verify_quotes(*s);
		s++;
		len++;
	}
	return (len);
}

static char	*copyword(char const *s, char c, size_t len, int count)
{
	char	*str;
	char	*tmp;

	if (!*s)
		return (NULL);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	tmp = str;
	while (*s && *s == c)
		s++;
	while (*s && *s != c && count == 1)
	{
		count = verify_quotes(*s);
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
	int count;

	count = 0;
	i = 0;
	nstr = nstrings(s, c, count);
	arr = malloc(sizeof(char *) * (nstr + 1));
	if (!arr)
		return (NULL);
	while (i < nstr)
	{
		while (*s)
		{
			count = verify_quotes(*s);
			while (*s && *s == c && count == 1)
					s++;
			strlen = strsize(s, c, count);
			arr[i++] = copyword(s, c, strlen, count);
			s = s + strlen;
		}
	}
	arr[i] = NULL;
	return (arr);
}
