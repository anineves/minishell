/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:19:12 by mimoreir          #+#    #+#             */
/*   Updated: 2022/12/05 09:19:13 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hexlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num)
	{
		num = num / 16;
		len ++;
	}
	return (len);
}

void	printlowerhex(unsigned int num)
{
	const char	base[17] = "0123456789abcdef";

	if (num >= 16)
	{
		printlowerhex(num / 16);
		ft_putchar_fd(base[num % 16], 1);
	}
	else
	{
		ft_putchar_fd(base[num % 16], 1);
	}
}

void	printupperhex(unsigned int num)
{
	const char	base[17] = "0123456789ABCDEF";

	if (num >= 16)
	{
		printupperhex(num / 16);
		ft_putchar_fd(base[num % 16], 1);
	}
	else
	{
		ft_putchar_fd(base[num % 16], 1);
	}
}

int	printhexa(unsigned int num, const char format)
{
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if (format == 'x')
		printlowerhex(num);
	else
		printupperhex(num);
	return (hexlen(num));
}
