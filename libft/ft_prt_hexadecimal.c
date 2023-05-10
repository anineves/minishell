#include "libft.h"


size_t	ft_strlen_hexa(unsigned int number)
{
	size_t	len;

	len = 0;
	while (number != 0)
	{
		len++;
		number = number / 16;
	}
	return (len);
}

void	ft_puthexa(unsigned int number, const char format)
{
	if (number >= 16)
	{
		ft_puthexa(number / 16, format);
		ft_puthexa(number % 16, format);
	}
	else
	{
		if (number <= 9)
			ft_putchar_fd((number + 48), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((number - 10 + 'a'), 1);
			else if (format == 'X')
				ft_putchar_fd((number - 10 + 'A'), 1);
		}
	}
}

int	ft_prt_hexadecimal(unsigned int number, const char format)
{
	if (number == 0)
		return (write(1, "0", 1));
	else
		ft_puthexa(number, format);
	return (ft_strlen_hexa(number));
}


