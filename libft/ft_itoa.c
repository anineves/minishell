/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:38:07 by mimoreir          #+#    #+#             */
/*   Updated: 2022/11/21 11:38:14 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ndigits(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	char	*num;

	i = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = ndigits(n);
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	if (n < 0)
	{
		num[0] = '-';
		n *= -1;
	}
	num[len] = '\0';
	while (n)
	{
		num[len - i++] = (n % 10) + '0';
		n = n / 10;
	}
	return (num);
}
