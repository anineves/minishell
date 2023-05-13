/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:28:36 by mimoreir          #+#    #+#             */
/*   Updated: 2022/12/02 09:28:37 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*initsave(char *save)
{
	if (!save)
	{
		save = malloc(1 * sizeof(char));
		*save = '\0';
	}
	return (save);
}
