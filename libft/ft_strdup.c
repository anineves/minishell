/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:17:16 by mimoreir          #+#    #+#             */
/*   Updated: 2022/11/05 10:17:18 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*c;
	char	*a;
	int		size;

	size = ft_strlen(src);
	c = malloc(size + 1);
	if (!c)
		return (NULL);
	a = c;
	while (*src)
	{
		*a = *src;
		a++;
		src++;
	}
	*a = '\0';
	return (c);
}
