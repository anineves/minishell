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
