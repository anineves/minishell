/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:41:18 by asousa-n          #+#    #+#             */
/*   Updated: 2022/10/28 15:42:26 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*pt_string1;
	unsigned char	*pt_string2;

	pt_string1 = (unsigned char *)s1;
	pt_string2 = (unsigned char *)s2;
	i = 0;
	while (i < n && pt_string1[i] == pt_string2[i])
		i++;
	if (i == n)
		return (0);
	return (pt_string1[i] - pt_string2[i]);
}
/*
int main ()
{
	int arr1[] = {1, 2};
	int arr2[] = {1, 3};
	
	printf("%d", ft_memcmp(arr1, arr2, 2 * sizeof(int)));
	return (0);
} */
