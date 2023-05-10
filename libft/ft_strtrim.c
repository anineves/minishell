##include "libft.h"

static int      ft_set(char c, char const *set)
{
        size_t  i;

        i = 0;
        while (set[i])
        {
                if (set[i] == c)
                        return (1);
                i++;
        }
        return (0);
}
char    *ft_strtrim(char const *s1, char const *set)
{
        char    *trimmed;
        size_t  i;
        size_t  start;
        size_t  end;
       
        if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
        i = 0;
        start = 0;
        end = ft_strlen(s1);
        while (s1[start] != '\0' && ft_set(s1[start], set) == 1)
                start++;
        while (end > start && ft_set(s1[end - 1], set) == 1)
                end--;
        trimmed = malloc(sizeof(char) * (end - start + 1));

        if (trimmed == NULL)
                return (NULL);

        while (start < end)
                trimmed[i++] = s1[start++];
        trimmed[i] = 0;
        return (trimmed);
}        
