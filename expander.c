#include "minishell.h"

char *get_env_value(const char *var) 
{
    char *value = getenv(var);
    if (value == NULL)
    	return NULL;
    return ft_strdup(value);
}

char *ft_nstrdup(const char *s, size_t n) 
{
    size_t len;
    char *sub;
    
    len = 0;
    while (len < n && s[len] != '\0') {
        len++;
    }
    sub = malloc(len + 1);
    if (sub != NULL) {
        ft_memcpy(sub, s, len);
        sub[len] = '\0';
    }
    return sub;
}

void ft_expander(t_global *global, char *input) 
{
	(void) global;
    char *start = input;
    char *end;
    size_t var_len;
    char *variable;
    char *value;
    size_t value_len;
    
    while (*start != '\0') 
    {
        if (*start == '$') 
        {
            start++;
            end = start;
            while (*end != '\0' && *end != ' ' && *end != '\t') 
                end++;
            var_len = end - start;
            variable = ft_nstrdup(start, var_len);
            value = get_env_value(variable);
            if (value != NULL) 
            {
                value_len = ft_strlen(value);
                ft_memmove(start + value_len, end, ft_strlen(end) + 1);
                ft_memcpy(start, value, value_len);
                free(value);
            }
            free(variable);
        } 
        else 
            start++;
    }
}
