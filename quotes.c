#include "minishell.h"

void rmvQuotes(char* str)
{
    int i;
    int j;
    int len;
    int inDquotes;
    int inSquotes;

    i = 0;
    j = 0;
    inSquotes = 0;
    inDquotes = 0;
    len = ft_strlen(str);
    while (i < len)
    {
        if (str[i] == '\"')
            inDquotes = !inDquotes;
         else if (str[i] == '\'')
            inSquotes = !inSquotes;
        if (str[i] != '\"' && str[i] != '\'')
            str[j++] = str[i];
        else if ((str[i] == '\"' && inSquotes) ||(str[i] == '\'' && inDquotes))
        	str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
}

bool closed_quotes2(int single_quote, int double_quote)
{
	if (single_quote == 1 || double_quote == 1)
	{
        	printf("unclosed quotes\n");
        	return (0);
    	}
    	else
        	return (1);
}

bool closed_quotes(char *input)
{
    int tam;
    int single_quote = 0;
    int double_quote = 0;
    int i;

    i = 0;
    single_quote = 0;
    double_quote = 0;
    tam = ft_strlen(input);
    while (i < tam)
    {
        if (input[i] == '\'')
        {
            if (double_quote % 2 == 0)
                single_quote = !single_quote;
        }
        else if (input[i] == '\"')
        {
            if (single_quote % 2 == 0)
                double_quote = !double_quote;
        }
        i++;
    }
    return (closed_quotes2(single_quote, double_quote));
}
