/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:27:54 by mimoreir          #+#    #+#             */
/*   Updated: 2022/12/02 09:27:56 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*readtostr(int fd, char *save)
{
	char	*buf;
	char	*tmp;
	int		i;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (1)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free (buf);
			free (save);
			return (NULL);
		}
		buf[i] = '\0';
		tmp = ft_strjoin(save, buf);
		free(save);
		save = tmp;
		if (ft_strchr(buf, '\n') || i == 0)
			break ;
	}
	free(buf);
	return (save);
}

char	*processaved(char *save)
{
	char	*line;
	char	*it;
	int		i;

	i = 0;
	if (!*save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	it = line;
	while (*save && *save != '\n')
		*it++ = *save++;
	if (*save == '\n')
	{
		*it++ = *save;
	}
	*it = '\0';
	return (line);
}

char	*ft_clearsave(char *save)
{
	char	*it;
	char	*s;
	size_t	i;

	i = 0;
	if (!save)
		return (NULL);
	it = save;
	while (*it && *it != '\n')
		it++;
	if (*it == '\n')
		it++;
	if (!ft_strlen(it))
	{
		free(save);
		return (NULL);
	}
	s = malloc(sizeof(char) * (ft_strlen(it) + 1));
	if (!s)
		return (NULL);
	while (*it)
		s[i++] = *it++;
	s[i] = '\0';
	free(save);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*save[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = initsave(save[fd]);
	if (!(ft_strchr(save[fd], '\n')))
		save[fd] = readtostr(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = processaved(save[fd]);
	save[fd] = ft_clearsave(save[fd]);
	return (line);
}
