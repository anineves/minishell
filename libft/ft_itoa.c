#include "libft.h"
static int	ft_digits(int n)
{
	int	digits;

	digits = 0;
	if (n <= 0)
		digits++;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	size_t	digits;
	int		signal;
	char	*result;

	digits = ft_digits(n);
	signal = 1;
	result = malloc((digits + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[digits] = '\0';
	if (n < 0)
	{
		signal = -1;
		result[0] = '-';
	}
	else if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		digits--;
		result[digits] = (n % 10 * signal) + '0';
		n = n / 10;
	}
	return (result);
}
/*
int     main(void)
{
        printf("%s\n", ft_itoa(1342345));
} */
