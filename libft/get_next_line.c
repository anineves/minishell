/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:30:28 by asousa-n          #+#    #+#             */
/*   Updated: 2022/11/14 15:30:31 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//remove a linha lida. Ela recebe como parâmetro a static , 
//nela eu procuro até a quebra de linha \n ou até chegar no final,
//se chega a EOF, dou um free na variável e retorno NULL , senão, 
//eu malloco uma nova variavel com o (tamanho total de backup, 
//menos o tamanho da linha),
//copio o restante de backup pra uma nova variável e dou free nela.

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

// bBuscar linha parea returnar
// Como parâmetro ainda vamos usar o backup, faço uma verificação 
//se a backup não está com o primeiro caracter como null byte ('\0')
//percorro ela inteira até achar uma ('\n') ou o final dela, 
//crio com o malloc uma string com o tamanho que li + 2 espaços,
// pra caso haja um \n ,
//eu coloque ele e logo em seguida o (\0) e retorno essa linha.
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
//Ler arquivo
//recebe como parâmetro o fd do arquivo e a variavel estática.
//crio um buffer com o tamnaho do BUFFER_SIZE e uso a função read() 
//pra ler o arquivo até encontrar o final dele - que seria retornado 
//0 - ou até encontrar uma linha (\n)
//caso ocorra algum erro, o laço de repetição é parado pois vai ser
// retornado -1,
//free a variavel buffer que tinha mallocado e retorno NULL,
//caso contrário, uso a função ft_strjoin()(onde adicionei free) 
//para juntar o conteúdo de backup com o buffer.

char	*ft_read_file(int fd, char *backup)
{
	char	*buffer;
	ssize_t	byte_read;

	if (!backup)
		backup = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
//inicializo em 1 para entrar no loop pela primeira ve
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1 || (byte_read == 0 && backup == NULL))
// porque se read der erro devolve -1
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
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = ft_read_file(fd, backup);
	//chamo a funcao que vai ler do buffer e guardo a nova backup.
	if (!backup)
		return (NULL);
	line = ft_get_line(backup); // a linha a ser usada
	backup = ft_remove(backup); //remove a linha lida.
	return (line);
}
/*
int main()
{
	int fd = open("teste.txt", O_RDONLY);
	//char *s;	
	//s = get_next_line(fd);
	//printf("linha1 %s", s);
	printf("linha2 %s", get_next_line(fd));
	printf("linha3 %s", get_next_line(fd));
	printf("linha4 %s", get_next_line(fd));
	//free(s);
	//close(fd);
	return 0;
} */
