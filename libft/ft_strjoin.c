/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:17:31 by mimoreir          #+#    #+#             */
/*   Updated: 2022/11/05 10:17:54 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	char	*aux;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	new = (char *)malloc(len1 + len2 + 1);
	if (!new)
		return (NULL);
	aux = new;
	ft_memcpy(aux, s1, len1);
	aux = aux + len1;
	ft_memcpy(aux, s2, len2);
	aux = aux + len2;
	*aux = '\0';
	return (new);
}
