#include "minishell.h"

char	*advance_first_word(char *start)
{
	int	count;

	if (*start == ' ')
		start++;
	while (1)
	{
		count = verify_quotes(*start);
		if (count == 1 && *start == ' ')
			start++;
		else if (count == 0 && *start == ' ')
			break ;
		else
			start++;
		if (!*start)
			break ;
	}
	if (*start)
		start++;
	return (start);
}

size_t	len_word(char *start)
{
	size_t	len;
	int		count;

	len = 0;
	while (1)
	{
		count = verify_quotes(*start);
		if (count == 1 && *start == ' ')
			len++;
		else if (count == 0 && *start == ' ')
			break ;
		else
			len++;
		start++;
		if (!*start)
			break ;
	}
	return (len);
}

char	*advance_and_clear(char *start)
{
	int	count;

	while (1)
	{
		count = verify_quotes(*start);
		if (count == 1 && *start == ' ')
			*start = ' ';
		else if (count == 0 && *start == ' ')
			break ;
		else
			*start = ' ';
		start++;
		if (!*start)
			break ;
	}
	if (*start && *start == ' ')
		start++;
	if (*start == '>' || *start == '<')
	{
		start++;
		if (*start == '>' || *start == '<')
			start++;
		start = advance_first_word(start);
	}
	return (start);
}

char	*find_words_after_red(char *start)
{
	char	*tmp;
	char	*new;
	char	*aux;

	new = ft_calloc(1, 1);
	tmp = NULL;
	if (*start == ' ')
		start++;
	start = advance_first_word(start);
	while (*start && *start != '|')
	{
		tmp = copy_len(start, len_word(start));
		aux = ft_strjoin(new, tmp);
		free(tmp);
		free(new);
		tmp = ft_charjoin(aux, ' ');
		free(aux);
		new = tmp;
		start = advance_and_clear(start);
	}
	return (new);
}
