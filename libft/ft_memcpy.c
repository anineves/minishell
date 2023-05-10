/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:13:05 by asousa-n          #+#    #+#             */
/*   Updated: 2022/10/31 14:13:55 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
        size_t  i;
        char    *pt_dest;
        char    *pt_src;

        pt_dest = (char *)dest;
        pt_src = (char *)src;
        i = 0;
        if(!src && !dest)
                return(NULL);
        while (i < n)
        {
                pt_dest[i] = pt_src[i];
                i++;
        }
        return (dest);
}
/*
int main ()
{
        int arr1[] = {3, 4};
        int arr2[] = {1, 2};
        printf("%d %d", arr2[0], arr2[1]);
        ft_memcpy (arr2, arr1, 2 * sizeof(int));
        printf("%d %d\n", arr2[0], arr2[1]);
        return (0);
}
*/
