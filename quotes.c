/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:31:39 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/14 00:29:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rmv_quotes(char *str)
{
	int	i;
	int	j;
	int	len;
	int	indquotes;
	int	insquotes;

	i = 0;
	j = 0;
	insquotes = 0;
	indquotes = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == '\"')
			indquotes = !indquotes;
		else if (str[i] == '\'')
			insquotes = !insquotes;
		if (str[i] != '\"' && str[i] != '\'')
			str[j++] = str[i];
		if ((str[i] == '\"' && insquotes) || (str[i] == '\'' && indquotes))
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}

bool	closed_quotes2(int single_quote, int double_quote)
{
	if (single_quote == 1 || double_quote == 1)
	{
		printf("unclosed quotes\n");
		return (0);
	}
	else
		return (1);
}

bool	closed_quotes(char *input)
{
	int	tam;
	int	single_quote;
	int	double_quote;
	int	i;

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
