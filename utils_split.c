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

static size_t	nstrings(char const *s, char c)
{
	int i;
        int n;
        int inDquotes;
        int inSquotes;

	inDquotes = 0;
	inSquotes = 0;
        i = 0;
        n = 0;
        while (s && s[i])
        {
        	if (s[i] == '"')
			inDquotes = !inDquotes;
		if (s[i] == '\'')
			inSquotes = !inSquotes;
                if (s[i] != c && s[i] != '"' && s[i] != '\'')
                {
                        n++;
                        while (s[i] != '\0' && (s[i] != c || (s[i] == c && (inDquotes || inSquotes))))
                        {
				if (s[i] == '"')
					inDquotes = !inDquotes;
				if (s[i] == '\'')
					inSquotes = !inSquotes;
				i++;
                        }
                }
                else
                        i++;
        }
        //printf("%d\n", n);
        return (n);
}

static size_t	strsize(char const *s, char c)
{
	size_t	len;
	int		inQuotes = 0;

	len = 0;
	inQuotes = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s == '"' || *s == '\'')
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
		if (*s == '"' || *s == '\'')
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

