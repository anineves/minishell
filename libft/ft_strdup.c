/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:17:16 by mimoreir          #+#    #+#             */
/*   Updated: 2022/11/05 10:17:18 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(char *s)
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
