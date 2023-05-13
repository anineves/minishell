/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <mimoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:24:16 by mimoreir          #+#    #+#             */
/*   Updated: 2023/05/13 15:40:09 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	verify_input(t_data *shell)
{
	char	*it;

	it = shell->cmd;
	while (*it == ' ' || *it == '\t')
		it++;
	if (*it == '\0')
		return (2);
	return (0);
}
