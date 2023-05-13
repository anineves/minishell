/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:15:14 by mimoreir          #+#    #+#             */
/*   Updated: 2022/11/05 10:15:16 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;
	int				res;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	res = 0;
	while (i < n)
	{
		if (*a != *b)
		{
			res = *a - *b;
			break ;
		}
		a++;
		b++;
		i++;
	}
	return (res);
}
