/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:04:53 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/24 11:51:59 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lst_add_back(t_data **shell, t_data *new)
{
	t_data	*it;

	if (*shell == NULL)
	{
		*shell = new;
	}
	else
	{
		it = (*shell);
		while (it->next != NULL)
			it = it->next;
		it->next = new;
	}
}

t_data	*new_node(char *start, size_t len, int red)
{
	t_data	*new;
	char	*tmp;
	char	*aux;

	new = (t_data *)malloc(sizeof(t_data));
	new->cmd = copy_len(start, len);
	new->flag = red;
	if (red == HEREDOC || red == RD_IN || red == APPEND || red == RD_OUT)
	{
		tmp = find_words_after_red(start + len + 1);
		aux = ft_strjoin(new->cmd, tmp);
		free(new->cmd);
		free(tmp);
		tmp = ft_strtrim(aux, " ");
		free(aux);
		new->cmd = tmp;
	}
	new->next = NULL;
	return (new);
}

int	is_ridirection(char	*str)
{
	if (ft_strncmp(str, ">>", 2) == 0)
		return (2);
	if (ft_strncmp(str, "<<", 2) == 0)
		return (2);
	if (ft_strncmp(str, "|", 1) == 0)
		return (1);
	if (ft_strncmp(str, "<", 1) == 0)
		return (1);
	if (ft_strncmp(str, ">", 1) == 0)
		return (1);
	return (0);
}

int	get_red(char *str)
{
	if (ft_strncmp(str, "|", 1) == 0)
		return (PIPE);
	if (ft_strncmp(str, "<<", 2) == 0)
		return (HEREDOC);
	if (ft_strncmp(str, ">>", 2) == 0)
		return (APPEND);
	if (ft_strncmp(str, "<", 1) == 0)
		return (RD_IN);
	if (ft_strncmp(str, ">", 1) == 0)
		return (RD_OUT);
	return (0);
}

void	create_data(t_data **shell, char *input, int count, char *end)
{
	char	*start;

	start = input;
	end = input;
	while (*end)
	{
		while (*end && (*end == ' ' || *end == '\t'))
			end++;
		while (*end)
		{
			count = verify_quotes(*end);
			if (count == 0 && (is_ridirection(end) != 0))
				break ;
			end++;
		}
		lst_add_back(shell, new_node(start, (end - start), get_red(end)));
		if (*end != '\0')
		{
			end = end + is_ridirection(end);
			while (*end && (*end == ' ' || *end == '\t'))
				end++;
			start = end;
		}
	}
}
