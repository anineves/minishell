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
	size_t	size;

	size = ft_strlen(src) + 1;
	c = (char *)malloc(size);
	if (!c)
		return (NULL);
	ft_memcpy(c, src, size);
	return (c);
}
