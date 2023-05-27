/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <mimoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:24:16 by mimoreir          #+#    #+#             */
/*   Updated: 2023/05/27 15:18:26 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdbool.h>

#include "minishell.h"
#include <stdbool.h>

void rmvSpaces(char *str)
{
	int i;
	int j;
	int len;
	int inDquotes;
	int inSquotes;
	int space;

	i = 0;
	j = 0;
	inSquotes = 0;
	inDquotes = 0;
	space = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == '\"')
			inDquotes = !inDquotes;
		else if (str[i] == '\'')
			inSquotes = !inSquotes;
		if ((str[i] == ' ' && !space) || inDquotes || inSquotes)
		{
			str[j++] = str[i];
			space = (str[i] == ' ');
		}
		else if (str[i] != ' ')
		{
			str[j++] = str[i];
			space = 0;
		}
		i++;
	}
	str[j] = '\0';
}

bool last_char(char *input)
{
	int i;

	i = 0;
	while(input[i] != '\0')
		i++;
	i--;
	while(input[i] == 32)
		i--;
	if((input[i] == '|') || (input[i] == '<') || (input[i] == '>'))
	{
		printf("Unexpected last char \n");
		return(0);
	}
	return(1);
}

bool first_char(char *input)
{
	int i;

	i = 0;
	while(input[i] == 32)
		i++;
	if((input[i] == '|') || (input[i] == '<'))
	{
		printf("Unexpected first char \n");
		return(0);
	}
	return(1);
}

int	verify_input(char *input)
{
	char	*it;

	it = input;
	while (*it == ' ' || *it == '\t')
		it++;
	if (*it == '\0')
		return (0);
	if (!closed_quotes(input))
		return (0);
	if (!first_char(input))
		return (0);
	if (!last_char(input))
		return (0);
	rmvSpaces(input);
	return (1);
}
