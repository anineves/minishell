/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <mimoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:19:40 by mimoreir          #+#    #+#             */
/*   Updated: 2023/05/13 15:30:24 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>
# include <string.h>
# include <signal.h>
# include <errno.h>
# include <fcntl.h>
# include <termios.h>

typedef struct s_data
{
	char	*cmd;
}			t_data;

void	init_signals(void);
void	sig_handler(int sig);
int		verify_input(t_data *shell);

#endif
