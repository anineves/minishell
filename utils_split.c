/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:16:48 by mimoreir          #+#    #+#             */
/*   Updated: 2023/05/30 22:27:37 by marvin           ###   ########.fr       */
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
        	if (s[i] == '"' && !inSquotes)
				inDquotes = !inDquotes;
			if (s[i] == '\'' && !inDquotes)
				inSquotes = !inSquotes;
            if (s[i] != c )
            {
                n++;
                while (s[i] != '\0' && (s[i] != c || (s[i] == c && (inDquotes || inSquotes))))
                {
					i++;
					if (s[i] == '"' && !inSquotes)
						inDquotes = !inDquotes;
					if (s[i] == '\'' && !inDquotes)
						inSquotes = !inSquotes;
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
	int inDquotes;
    int inSquotes;

	inDquotes = 0;
	inSquotes = 0;

	len = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{

        if (*s == '"' && !inSquotes)
			inDquotes = !inDquotes;
		if (*s == '\'' && !inDquotes)
			inSquotes = !inSquotes;
		if (*s == c && !inDquotes && !inSquotes)
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
	int inDquotes;
    int inSquotes;

	inDquotes = 0;
	inSquotes = 0;
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
		if (*s == c && !inDquotes && !inSquotes)
			break;
		if (*s == '"' && !inSquotes)
			inDquotes = !inDquotes;
		else if (*s == '\'' && !inDquotes)
			inSquotes = !inSquotes;
		if((*s == '"' && !inSquotes ) || (*s == '\'' && !inDquotes ))
			s++;
		else
		{
			*tmp = *s;
			tmp++;
			s++;
		}
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
		//printf("word %s\n", s);
		arr[i++] = copyword(s, c, strlen);
		s += strlen;
	}
	arr[i] = NULL;
	return (arr);
}


