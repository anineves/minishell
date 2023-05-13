/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:17:05 by mimoreir          #+#    #+#             */
/*   Updated: 2022/11/05 10:17:06 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;
	char	a;

	tmp = (char *)s;
	a = (char)c;
	while (*tmp)
	{
		if (*tmp == a)
			return (tmp);
		tmp++;
	}
	if (*tmp == '\0' && a == '\0')
		return (tmp);
	else
		return (NULL);
}
