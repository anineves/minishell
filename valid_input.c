/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:24:16 by mimoreir          #+#    #+#             */
/*   Updated: 2023/06/24 13:01:42 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdbool.h>

void	rmv_spaces(char *str, int i, int j, int space)
{
	int	len;
	int	count;

	len = ft_strlen(str);
	while (str[i] == ' ' || str[i] == '\t')
			i++;
	while (i < len)
	{
		count = verify_quotes(str[i]);
		if (count == 1 || ((str[i] != ' ' && str[i] != '\t') && count == 0))
		{
			str[j++] = str[i];
			space = 0;
		}
		else if (((str[i] == ' ' || str[i] == '\t') && !space) && count == 0)
		{
			str[j++] = ' ';
			space = 1;
		}
		i++;
	}
	str[j] = '\0';
}

bool	last_char(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
		i++;
	i--;
	while (input[i] == 32)
		i--;
	if ((input[i] == '|') || (input[i] == '<') || (input[i] == '>'))
	{
		printf("bash: syntax error near unexpected token `newline' \n");
		return (0);
	}
	return (1);
}

bool	first_char(char *input)
{
	int	i;

	i = 0;
	while (input[i] == 32)
		i++;
	if ((input[i] == '|') || (input[i] == '<'))
	{
		printf("Unexpected first char \n");
		return (0);
	}
	return (1);
}

bool	repeat_red(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		count = verify_quotes(input[i]);
		if ((input[i] == '<' || input[i] == '>') \
			&& count == 0)
		{
			if (input[i + 1] == ' ')
			{
				if (input[i + 2] == '<' || input[i +2] == '>' \
					|| input[i +2] == '|')
				{
					printf("bash: syntax error near unexpected token \
						`%c' \n", input[i + 2]);
					return (0);
				}
			}
		}
		i++;
	}
	return (1);
}

int	verify_input(char *input)
{
	char	*it;
	int		i;
	int		j;
	int		space;

	i = 0;
	j = 0;
	space = 0;
	it = input;
	while (*it == ' ' || *it == '\t' || *it == EOF)
		it++;
	if (*it == '\0')
		return (0);
	if (!closed_quotes(input))
		return (0);
	if (!last_char(input))
		return (0);
	if (!repeat_red(input))
		return (0);
	rmv_spaces(input, i, j, space);
	return (1);
}
