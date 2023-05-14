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

int	closed_quotes(t_data *shell)
{
	int		i;
	char	d_quote;
	bool	open;

	i = 0;
	d_quote = '\"';
	open = false;
	while (shell->input[i])
	{
		if (open && shell->input[i] == d_quote)
			open = false;
		else if (!open && ft_strchr("\"", shell->input[i]))
		{
			d_quote = shell->input[i];
			open = true;
		}
		i++;
	}
	if (open)
	{
		printf("unclosed quotes \n");
		return (0);
	}
	return (1);
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
