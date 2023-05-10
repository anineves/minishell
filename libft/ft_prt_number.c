#include "libft.h"

int	ft_prt_number(int n)
{
	int		len;
	char	*number;

	len = 0;
	number = ft_itoa(n);
	len = ft_prt_string(number);
	free(number);
	return (len);
}
