#include "libft.h"


static int      count_word(char const *s, char c)
{
        int i;
        int word;

        i = 0;
        word = 0;
        while (s && s[i])
        {
                if (s[i] != c)
                {
                        word++;
                        while (s[i] != c && s[i] != '\0')
                                i++;
                }
                else
                        i++;
        }
        return (word);
}

static int      size_word(char const *s, char c, int i)
{
        int     size;

        size = 0;
        while (s[i] != c && s[i] != '\0')
        {
                size++;
                i++;
        }
        return (size);
}

char            **ft_split(char const *s, char c)
{
int             i;
        int             word;
        char    **str;
        int             size;
        int             j;

        i = 0;
        j = -1;
        word = count_word(s, c);
        str = (char **)malloc((word + 1) * sizeof(char *));
        if (!str)
                return (NULL);
        while (++j < word)
        {
                while (s[i] == c)
                        i++;
                size = size_word(s, c, i);
                str[j] = ft_substr(s, i, size);
                if (!str)
                        return (NULL);
                i += size;
        }
        str[j] = 0;
        return (str);

}

/*
int             main()
{
        char    str[] = "Ola Bom Dia";
        char    **split;
        split = ft_split(str, ' ');
        printf("%s\n", split[0]);
        printf("%s\n", split[1]);
        return (0);
}
 */                      
