/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:16:48 by mimoreir          #+#    #+#             */
/*   Updated: 2022/11/05 10:16:53 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
			continue ;
		}
		s++;
	}
	return (n);
}

static size_t	strsize(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static char	*copyword(char const *s, char c, size_t len)
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
	while (*s && *s != c)
	{
		*tmp = *s;
		tmp++;
		s++;
	}
	*tmp = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
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
	while (i < nstr)
	{
		while (*s)
		{
			while (*s && *s == c)
					s++;
			strlen = strsize(s, c);
			arr[i++] = copyword(s, c, strlen);
			s = s + strlen;
		}
	}
	arr[i] = NULL;
	return (arr);
}
