/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:15:42 by mimoreir          #+#    #+#             */
/*   Updated: 2022/11/05 10:15:45 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*a;
	const char	*b;
	size_t		i;

	i = 0;
	a = dest;
	b = src;
	if (src == dest)
		return (dest);
	while (i < n)
	{
		*a = *b;
		a++;
		b++;
		i++;
	}
	return (dest);
}
