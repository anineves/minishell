#include "libft.h"

char
        *ft_strjoin(char const *s1, char const *s2)
{
        char    *newstr;
        size_t  i;
        size_t  j;
        size_t lens1;
        size_t lens2;
       
        if(!s1)
              return (NULL);
        lens1 = ft_strlen(s1);
        lens2 = ft_strlen(s2);
       
        newstr = (char*)malloc (sizeof(*s1) * (lens1 + lens2 + 1));
        if (!newstr)
                return (NULL);
        i = 0;
        j = 0;
        while (s1[i])
        {
                newstr[j++] = s1[i];
                i++;
        }
        i = 0;
        while (s2[i])
        {
                newstr[j++] = s2[i];
                i++;
        }
        newstr[j] = '\0';
        return (newstr);
}

