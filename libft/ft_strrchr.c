/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:23:44 by mimoreir          #+#    #+#             */
/*   Updated: 2022/11/05 10:23:46 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	*it;
	char	a;

	it = (char *)s;
	a = (char)c;
	tmp = NULL;
	while (*it)
	{
		if (*it == a)
			tmp = it;
		it++;
	}
	if (*it == '\0' && a == '\0')
		tmp = it;
	return (tmp);
}
