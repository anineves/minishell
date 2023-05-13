/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:18:53 by mimoreir          #+#    #+#             */
/*   Updated: 2022/12/05 09:18:55 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printchar(const char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	printstr(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	formats(va_list args, const char format)
{
	int	printed;

	printed = 0;
	if (format == 'c')
		printed += printchar(va_arg(args, int));
	else if (format == 's')
		printed += printstr(va_arg(args, char *));
	else if (format == 'p')
		printed += printpointer(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		printed += printnbr(va_arg(args, int));
	else if (format == 'u')
		printed += printuns(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		printed += printhexa(va_arg(args, unsigned int), format);
	else if (format == '%')
		printed += printchar(format);
	return (printed);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		printed;

	i = 0;
	printed = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			printed += formats(args, s[i]);
		}
		else
			printed += printchar(s[i]);
		i++;
	}
	va_end(args);
	return (printed);
}
