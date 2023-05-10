#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
        int     i;
        char    *str;

        i = 0;
        if (s == NULL || f == NULL)
                return (NULL);
        str = malloc(sizeof(char) * ft_strlen(s) + 1);
        if (str == NULL)
                return (NULL);
        while (s[i] != '\0')
        {
                str[i] = f(i, s[i]);
                i++;
        }
        str[i] = '\0';
        return (str);
}
