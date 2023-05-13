/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:20:39 by mimoreir          #+#    #+#             */
/*   Updated: 2022/11/05 10:20:41 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char			*a;
	char			*b;
	unsigned int	i;

	a = dest;
	b = src;
	i = 0;
	if (size > 0)
	{
		if (size > 1)
		{
			while (*b != '\0' && i < (size - 1))
			{
				*a = *b;
				a++;
				b++;
				i++;
			}
		}
		*a = '\0';
	}
	return (ft_strlen(src));
}
