/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:30:27 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/14 00:12:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

char	*expand_exit_status(char *new)
{
    char *num;
    char *tmp;

    num = ft_itoa(g_exit_status);
    tmp = ft_strjoin(new, num);
    free(new);
    free(num);
    new = tmp;

    return new;
}

char	*expand_variable(t_global *global, char **it, char *new)
{
	char	*tmp;
	char	*num;
	char	*aux;

	if (**it == '?')
	{
		(*it)++;
		new = expand_exit_status(new);
	}
	else
	{
		tmp = *it;
		while (**it != ' ' && **it != '"' && **it != '\'' && **it)
			(*it)++;
		num = copy_len(tmp, *it - tmp);
		aux = is_env(global, num);
		tmp = ft_strjoin(new, aux);
		free(num);
		free(new);
		free(aux);
		new = tmp;
	}

	return new;
}

bool	ft_verific_expand(char *it, int squote, int dquote)
{
	if ((*it == '$' && dquote == 1 && (((*(it - 2) == '<') && \
		(*(it - 3) == '<')) || ((*(it - 3) == '<') && (*(it - 4) == '<')))))
		return (0);
	if ((*it == '$' && squote == 0 && *(it + 1) != '~') && \
		(((*(it - 1) != '<') || (*(it - 2) != '<')) && \
		((*(it - 2) != '<') || (*(it - 3) != '<'))))
		return(1);
	else if ((*it == '$' && squote == 1) && (*it == '$' && dquote == 1))
		return(1);
	else 
		return(0);
}

char	*process_character(t_global *global, char *new, char **it) 
{
    (*it)++;
    new = expand_variable(global, it, new);
    return new;
}

char	*ft_expander(t_global *global, char *input) 
{
    char *new;
    char *it;
    int squote;
    int dquote;

    it = input;
    squote = 0;
    dquote = 0;
    new = ft_calloc(sizeof(char), 1);
    while (*it) 
    {
        switch_quotes(*it, &dquote, &squote);
        if (input[0] == '$' || ft_verific_expand(it, squote, dquote))
            new = process_character(global, new, &it);
        else 
        {
            char *tmp = ft_charjoin(new, *it);
            free(new);
            new = tmp;
            it++;
        }
    }
    return new;
}
