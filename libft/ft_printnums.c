/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:19:23 by mimoreir          #+#    #+#             */
/*   Updated: 2022/12/05 09:19:25 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numlen(int num)
{
	int	len;

	len = 0;
	if (num < 0)
		len++;
	while (num)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

int	printnbr(int num)
{
	ft_putnbr_fd(num, 1);
	if (num == 0)
		return (1);
	return (numlen(num));
}

int	lenptr(unsigned long long num)
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

void	printptr(unsigned long long num)
{
	const char	base[17] = "0123456789abcdef";

	if (num >= 16)
	{
		printptr(num / 16);
		ft_putchar_fd(base[num % 16], 1);
	}
	else
	{
		ft_putchar_fd(base[num % 16], 1);
	}
}

int	printpointer(unsigned long long ptr)
{
	int	printed;

	printed = 0;
	if (ptr == 0)
	{
		printed += printstr("(nil)");
		return (printed);
	}
	printed += printstr("0x");
	printptr(ptr);
	return (printed + lenptr(ptr));
}
