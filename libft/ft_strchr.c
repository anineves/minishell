/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:18:23 by asousa-n          #+#    #+#             */
/*   Updated: 2022/10/31 14:19:20 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>


char    *ft_strchr(const char *s, int c)
{
        unsigned int    i;

        i = 0;
        while (s[i])
        {
                if (s[i] == (char)c)
                        return ((char *)&s[i]);
                i++;
        }
        if ((char)c == s[i])
                return ((char *)&s[i]);
        return (NULL);
}

/*
int main()
{
    const char *s = "Olaa";
    char  c;

    c = 'a';
    printf("letra :%c\n", *ft_strchr(s, c));
    *ft_strchr(str, c);
    return (0);
}*/
