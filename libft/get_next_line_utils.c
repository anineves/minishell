/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:30:34 by asousa-n          #+#    #+#             */
/*   Updated: 2022/11/14 15:30:35 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"


char	*ft_free_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;
	size_t	lens1;
	size_t	lens2;

	if (!s1)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	newstr = (char *)malloc (sizeof(*s1) * (lens1 + lens2 + 1));
	if (!newstr)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		newstr[j++] = s1[i];
	i = -1;
	while (s2[++i])
		newstr[j++] = s2[i];
	newstr[j] = '\0';
	free(s1);
	return (newstr);
}

