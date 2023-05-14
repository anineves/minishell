/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <mimoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:24:16 by mimoreir          #+#    #+#             */
/*   Updated: 2023/05/13 18:20:49 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdbool.h>

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

bool closed_quotes(t_data *shell) 
{
    int tam;
    int single_quote = 0;
    int double_quote = 0;
    int i;
    
    i = 0;
    single_quote = 0;
    double_quote = 0;
    tam = ft_strlen(shell->input);
    while (i < tam) 
    {
        if (shell->input[i] == '\'') 
        {
            if (double_quote % 2 == 0)
                single_quote = !single_quote;
        }
        else if (shell->input[i] == '\"') 
        {
            if (single_quote % 2 == 0) 
                double_quote = !double_quote;
        }
        i++;
    }
    return (closed_quotes2(single_quote, double_quote));
}

void	rmv_spaces(t_data *shell)
{
	char	*new;
	char	*aux;

	aux = shell->input;
	new = ft_strtrim(shell->input, " \t");
	shell->input = new;
	free(aux);
}


int	verify_input(t_data *shell)
{
	char	*it;
	//char	**spl;
	char	*token;
	
	it = shell->input;
	while (*it == ' ' || *it == '\t')
		it++;
	if (*it == '\0')
		return (2);
	rmv_spaces(shell);
	if(!closed_quotes(shell))
		return(1);
	if (ft_strchr(shell->input, '|'))
	{
		token = ft_strtok(shell->input, "|");
		//shell->spl_in = spl;
		//int i = 0;
		while (token != NULL) 
		{
        		printf("%s \n", token);
        		token = ft_strtok(NULL, "|");
   		}
	}
	return (0);
}
