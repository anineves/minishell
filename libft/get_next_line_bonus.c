/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:48:12 by asousa-n          #+#    #+#             */
/*   Updated: 2022/11/19 11:48:19 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_remove(char *backup)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(backup) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (backup[i])
		line[j++] = backup[i++];
	line[j] = '\0';
	free(backup);
	return (line);
}

char	*ft_get_line(char *backup)
{
	char	*line;
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[size] && backup[size] != '\n')
		size++;
	line = ft_calloc(size + 2, sizeof(char));
	while (i <= size)
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_file(int fd, char *backup)
{
	char	*buffer;
	int		byte_read;

	if (!backup)
		backup = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1 || (byte_read == 0 && backup == NULL))
		{
			free(buffer);
			free(backup);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		backup = ft_free_strjoin(backup, buffer);
		if (ft_strchr(backup, '\n'))
			break ;
	}
	free(buffer);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup[FOPEN_MAX];
	char		*line;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	backup[fd] = ft_read_file(fd, backup[fd]);
	if (!backup[fd])
		return (NULL);
	line = ft_get_line(backup[fd]);
	backup[fd] = ft_remove(backup[fd]);
	return (line);
}

/*
int	main(void)
{
	char	*line;
	char	*line1;
	char	*line2;
	int		i;
	int		file;
	int		file2;
	int		file3;
	file = open("teste.txt", O_RDONLY);
	file2 = open("teste1.txt", O_RDONLY);
	file3 = open("teste2.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		printf("round ------------%d--------\n\n\n", i);
		line = get_next_line(file);
		printf("FILE : line [%02d]: %s \n", i, line);
		free(line);
		line1 = get_next_line(file2);
		printf("FILE2 : line [%02d]: %s\n", i, line1);
		free(line1);
		line2 = get_next_line(file3);
		printf("FILE 3 : line [%02d]: %s\n", i, line2);
		free(line2);
		i++;
	}
	close(file);
	close(file2);
	close(file3);
	return (0);
}*/
