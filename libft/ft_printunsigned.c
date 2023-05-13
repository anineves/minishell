/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:34:29 by mimoreir          #+#    #+#             */
/*   Updated: 2022/12/05 11:35:16 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	unsiglen(unsigned int num)
{
	int	len;

	len = 0;
	while (num)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = unsiglen(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	printuns(unsigned int num)
{
	char	*n;
	int		printed;

	printed = 0;
	if (num == 0)
	{
		printed += printchar('0');
	}
	else
	{
		n = ft_uitoa(num);
		printed += printstr(n);
		free(n);
	}
	return (printed);
}
