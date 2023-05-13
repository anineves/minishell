/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:30:26 by mimoreir          #+#    #+#             */
/*   Updated: 2022/11/05 11:30:28 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_located(char *p1, char *p2, size_t i, size_t len)
{
	while ((*p1 && *p2) && i < len)
	{
		if (*p1 != *p2)
			return (0);
		p1++;
		p2++;
		i++;
	}
	if (!*p2)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*ptr1;
	char	*ptr2;
	size_t	i;

	i = 0;
	ptr1 = (char *)big;
	ptr2 = (char *)little;
	if (ft_strlen(little) == 0)
		return (ptr1);
	while (i < len)
	{
		if (*ptr1 == *ptr2)
		{
			if (is_located(ptr1, ptr2, i, len))
				return (ptr1);
		}
		i++;
		ptr1++;
	}
	return (NULL);
}
