/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:25:00 by mimoreir          #+#    #+#             */
/*   Updated: 2022/11/05 10:25:02 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*aux;

	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (start-- && *s)
		s++;
	aux = substr;
	while (len && *s)
	{
		*aux = *s;
		len--;
		s++;
		aux++;
	}
	*aux = '\0';
	return (substr);
}
