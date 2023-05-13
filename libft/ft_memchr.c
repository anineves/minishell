/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:14:47 by mimoreir          #+#    #+#             */
/*   Updated: 2022/11/05 10:14:50 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void					*tmp;
	unsigned char			a;
	const unsigned char		*aux;
	size_t					i;

	i = 0;
	a = (unsigned char)c;
	aux = s;
	while (i < n)
	{
		if (*aux == a)
			break ;
		aux++;
		i++;
	}
	if (i == n)
		return (NULL);
	tmp = (void *)aux;
	return (tmp);
}
