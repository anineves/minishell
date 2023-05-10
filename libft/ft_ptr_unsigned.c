#include "libft.h"

size_t	ft_strlen_unumber(unsigned int number)
{
	size_t	len;

	len = 0;
	while (number != 0)
	{
		len++;
		number /= 10;
	}
	return (len);
}

char	*ft_un_itoa(unsigned int n)
{
	char	*number;
	size_t		len;

	len = ft_strlen_unumber(n);
	number = (char *)malloc((len + 1) * sizeof(char));
	if (!number)
		return (NULL);
	number[len] = '\0';
	while (n != 0)
	{
		number[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (number);
}

int	ft_prt_unsigned(unsigned int n)
{
	size_t		len;
	char	*number;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		number = ft_un_itoa(n);
		len+= ft_prt_string(number);
		free(number);
	}
	return (len);
}
