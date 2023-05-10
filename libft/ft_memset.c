/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:49:00 by asousa-n          #+#    #+#             */
/*   Updated: 2022/10/28 16:03:22 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*string;

	string = (char *)s;
	i = 0;
	while (i < n)
	{
		string[i] = c;
		i++;
	}
	return (s);
}
/* int main ()
{
	int arr1[] = {3, 4};
	int arr2[] = {1, 2};
	printf("%d %d", arr1[0], arr1[1]);
	ft_memset(arr1, 0, 2 * sizeof(int));
	printf("%d %d\n", arr1[0], arr1[1]);
	return (0);
} */
