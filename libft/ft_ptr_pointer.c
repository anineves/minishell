#include "libft.h"

size_t	ft_strlen_pointer(uintptr_t ptr)
{
	size_t	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

void	ft_putpointer(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_putpointer(ptr / 16);
		ft_putpointer(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_prt_char(ptr + 48);
		else
			ft_prt_char((ptr - 10 + 'a'));
	}
}

int	ft_prt_pointer(unsigned long long ptr)
{
	int	len;

	if (ptr == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	len = 2;
	ft_putpointer(ptr);
	len += ft_strlen_pointer(ptr);
	return (len);
}
