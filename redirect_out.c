/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:32:00 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/13 11:32:00 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

void	red_out_append(t_global *global, int read_fd)
{
	if (global->shell->flag == APPEND)
		append_to_file(global, read_fd, 0);
	if (global->shell->flag == RD_OUT)
		write_to_file(global, read_fd, 0);
}

void	repeat_redout(t_global *global, int read_fd, int fd)
{
	if (global->shell->cmd)
	{
		if (global->shell->next->flag == RD_OUT)
		{
			global->shell = go_to_next(global);
			write_to_file(global, read_fd, fd);
		}
		else if (global->shell->next->flag == APPEND)
		{
			global->shell = go_to_next(global);
			append_to_file(global, read_fd, fd);
		}
	}
}

void	append_to_file(t_global *global, int read_fd, int fd)
{
	char	*str;

	str = ft_strtrim(global->shell->next->cmd, " ");
	fd = open(str, O_APPEND | O_CREAT | O_RDWR, 0644);
	free(str);
	if (fd < 0)
	{
		printf("ERROR WITH FILE\n");
		return ;
	}
	repeat_redout(global, read_fd, fd);
	while (1)
	{
		str = get_next_line(read_fd);
		if (str)
		{
			if (g_exit_status == 127)
				fd = 2;
			write(fd, str, ft_strlen(str));
			free(str);
		}
		else
			break ;
	}
	close(fd);
}

void	write_to_file(t_global *global, int read_fd, int fd)
{
	char	*str;

	str = ft_strtrim(global->shell->next->cmd, " ");
	fd = open(str, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(str);
	if (fd < 0)
	{
		printf("ERROR WITH FILE\n");
		return ;
	}
	repeat_redout(global, read_fd, fd);
	while (1)
	{
		str = get_next_line(read_fd);
		if (str)
		{
			if (g_exit_status == 127)
				fd = 2;
			write(fd, str, ft_strlen(str));
			free(str);
		}
		else
			break ;
	}
	close(fd);
}
