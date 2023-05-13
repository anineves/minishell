/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:19:44 by mimoreir          #+#    #+#             */
/*   Updated: 2022/11/05 10:20:10 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	char			*a;

	i = 0;
	a = dest;
	if (size == 0)
		return (0);
	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	while (*a)
	{
		a++;
		i++;
	}
	while (i < (size -1) && *src)
	{
		*a = *src;
		a++;
		src++;
		i++;
	}
	*a = '\0';
	return (ft_strlen(dest) + ft_strlen(src));
}
