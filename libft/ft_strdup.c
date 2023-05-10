/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:54:53 by asousa-n          #+#    #+#             */
/*   Updated: 2022/10/31 14:58:23 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s)
{
        unsigned int    i;
        char                    *str;

        str = malloc(sizeof(char) * (ft_strlen(s) + 1));
        if (str == NULL)
                return (NULL);
        i = 0;
        while (s[i] != '\0')
        {
                str[i] = s[i];
                i++;
        }
        str[i] = '\0';
        return (str);
}

