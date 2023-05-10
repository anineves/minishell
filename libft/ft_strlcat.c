/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:13:01 by asousa-n          #+#    #+#             */
/*   Updated: 2022/10/28 14:27:48 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	tam_src;
	size_t  tam_dst;
	
	if (size == 0)
		return (ft_strlen(src));
		
	tam_src = ft_strlen(src);
	tam_dst = ft_strlen(dst);
	j = tam_dst;
	i = 0;

	if (size < tam_dst)
		return (tam_src + size);
	
	while (src[i] && j < (size - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (tam_dst + tam_src);
}
/*
int main ()
{
	char src[] = "Ola";
	char dst[] = "Tudo";
	size_t size = 12;
	int t ;
	
	t = printf("%d,\n", ft_strlcat(dst, src, size));

}
*/
