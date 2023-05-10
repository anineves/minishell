#include "libft.h"

int	ft_format(va_list args, const char format)
{
	if (format == 'c')
		return (ft_prt_char(va_arg(args, int)));
	else if (format == 's')
		return (ft_prt_string(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_prt_pointer(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_prt_number(va_arg(args, int)));
	else if (format == 'u')
		return (ft_prt_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_prt_hexadecimal(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_prt_char('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int	len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_format(args, str[i + 1]);
			i++;
		}
		else
			len += ft_prt_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
