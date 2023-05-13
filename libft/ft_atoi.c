/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:03:04 by mimoreir          #+#    #+#             */
/*   Updated: 2022/11/05 10:03:08 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *ptr)
{
	int		res;
	int		sign;
	char	*it;

	res = 0;
	sign = 1;
	it = (char *)ptr;
	while (*it == ' ' || (*it >= 9 && *it <= 13))
		it++;
	if (*it == '-' || *it == '+')
	{
		if (*it == '-')
			sign = -1;
		it++;
	}
	while (*it && *it >= '0' && *it <= '9')
	{
		res = res * 10 + (*it - '0');
		it++;
	}
	return (res * sign);
}
