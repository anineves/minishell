/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:19:40 by mimoreir          #+#    #+#             */
/*   Updated: 2023/06/03 16:12:11 by asousa-n         ###   ########.fr       */
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
# include <sys/stat.h>
# include <string.h>
# include <signal.h>
# include <errno.h>
# include <fcntl.h>
# include <termios.h>
# include <stdbool.h>

/*PIPE RELATED!!!*/

# define WRITE_END 1
# define READ_END 0
typedef enum
{
	EMPTY,
	PIPE,    // |
	HEREDOC,  // <<
	APPEND,  // >>
	RD_OUT,      // >
	RD_IN       // <
}		op_type;

typedef struct s_env
{
	char *key;
	char *value;
	struct s_env *next;
}	t_env;

typedef struct s_data
{
	char	*cmd;
	int		flag;
	struct s_data *next;
}	t_data;

typedef struct s_global
{
	t_data	*shell;
	char	**args;
	char	**copy_env;
	char	*old_path;
	int		len_env;
	int	fd_input;
	int	fd_output;
	int	fd_heredoc;
	char 	*path;
	char	**split_path;
	char	*cwd;
}	t_global;

void	init_signals(void);
void	sig_handler(int sig);
int		verify_input(char *input);
char	*ft_strtok(char *str, const char *delim);
char	*copy_len(char *src, size_t len);
bool	closed_quotes(char *input);
void	rmvQuotes(char* str);
void	create_data(t_data **shell, char *input);
void	lst_add_back(t_data **shell, t_data *new);
t_data	*new_node(char *start, size_t len, int red);
int		verify_quotes(char c);
void	execute(t_global *global);
void	ft_echo(t_global *global);
void	ft_pwd();
void 	ft_env(t_global *global);
void	ft_cd(t_global *global);
void	ft_exit(t_global *global);
void	ft_export(t_global *global);
char	**ft_split2(char const *s, char c);
int		ft_strcmp(char *str1, char *str2);
void	free_data(t_data **shell);
void	free_global(t_global *global);
size_t	size_env(char **env);
char	**init_env(char **env);
void	free_args(char	**args);
void	append_to_file(t_global *global, int read_fd);
void	write_to_file(t_global *global, int read_fd);
void	create_new_var(t_global *global);
size_t	size_env(char **env);
void ft_unset(t_global *global);
char	**rmv_var(t_global *global, int j, int size);
int	is_child_builtin(t_global *global);
void	execute_child_builtin(t_global *global);
int	is_parent_builtin(t_global *global);
void	execute_parent_builtin(t_global *global);
void	red_out_append(t_global *global, int read_fd);
void	red_in_heredoc(t_global *global);
void	verific_redin(t_global *global);

static inline void	ignore_signal(int n)
{
	(void)n;
	exit(130);
}
#endif
