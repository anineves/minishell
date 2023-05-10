/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:17:17 by asousa-n          #+#    #+#             */
/*   Updated: 2022/10/31 14:18:01 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
// A funcao calloc recebe dois parametros, a quantidade de elementos e o tamanho da memoria desse elemento. Alem disso inicia tudo a zeros
