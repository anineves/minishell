/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:24:36 by mimoreir          #+#    #+#             */
/*   Updated: 2022/11/05 10:24:37 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	i;
	size_t	first;
	size_t	last;

	first = 0;
	last = ft_strlen(s1);
	while (s1[first] && is_in_set(s1[first], set))
		first++;
	while (last > first && is_in_set(s1[last - 1], set))
		last--;
	trim = malloc(sizeof(char) * (last - first + 1));
	if (trim == NULL)
		return (NULL);
	i = 0;
	while (first < last)
		trim[i++] = s1[first++];
	trim[i] = '\0';
	return (trim);
}
