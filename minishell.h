/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:19:40 by mimoreir          #+#    #+#             */
/*   Updated: 2023/06/24 14:21:17 by asousa-n         ###   ########.fr       */
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

# define WRITE_END 1
# define READ_END 0

typedef enum red_type
{
	EMPTY,
	PIPE,
	HEREDOC,
	APPEND,
	RD_OUT,
	RD_IN
}		t_red_type;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_data
{
	char			*cmd;
	int				flag;
	struct s_data	*next;
}	t_data;

typedef struct s_global
{
	t_data	*shell;
	char	**args;
	char	**copy_env;
	char	*old_path;
	int		len_env;
	int		fd_input;
	int		fd_output;
	int		fd_heredoc;
	int		flag;
	char	*path;
	char	**split_path;
	char	*cwd;
}	t_global;

void		init_signals(void);
void		sig_handler(int sig);
int			verify_input(char *input);
char		*copy_len(char *src, size_t len);
bool		closed_quotes(char *input);
void		rmv_quotes(char *str);
void		create_data(t_data **shell, char *input, int count, char *end);
void		lst_add_back(t_data **shell, t_data *new);
t_data		*new_node(char *start, size_t len, int red);
int			verify_quotes(char c);
void		execute(t_global *global);
void		ft_echo(t_global *global);
void		ft_pwd(t_global *global);
void		ft_env(t_global *global);
void		ft_cd(t_global *global);
void		ft_exit(t_global *global);
void		ft_export(t_global *global);
char		**ft_split2(char const *s, char c);
int			ft_strcmp(char *str1, char *str2);
void		free_data(t_data **shell);
void		free_global(t_global *global);
size_t		size_env(char **env);
char		**init_env(char **env);
void		free_args(char	**args);
void		append_to_file(t_global *global, int read_fd, int fd);
void		write_to_file(t_global *global, int read_fd, int fd);
void		create_new_var(t_global *global);
size_t		size_env(char **env);
void		ft_unset(t_global *global);
char		**rmv_var(t_global *global, int j, int size);
int			is_child_builtin(t_global *global);
void		execute_child_builtin(t_global *global);
int			is_parent_builtin(t_global *global);
void		execute_parent_builtin(t_global *global);
void		red_out_append(t_global *global, int read_fd);
void		red_in_heredoc(t_global *global);
void		verific_redin(t_global *global);
char		*ft_expander(t_global *global, char *input, char *tmp);
t_data		*go_to_next(t_global *global);
char		*get_path(char **copy_env, char *path);
t_data		*go_to_next(t_global *global);
void		ft_close(t_global *global);
t_global	*init_global(char **env);
void		switch_quotes(char s, int *inDquotes, int *inSquotes);
void		sig_quit(int sig);
void		sig_int(int sig);
void		wait_and_exit_status(void);
void		open_pipes(t_global *global, int *pipe_fd);
char		*get_type_path(char *arg, t_global *global);
char		*ft_charjoin(char *s1, char c);
char		*is_env(t_global *global, char *temp);
void		execute_next_shell(t_global *global, char *path, int pipe_fd[2]);
void		final_exec(t_global *global, char *path);
char		*advance_first_word(char *start);
size_t		len_word(char *start);
char		*advance_and_clear(char *start);
char		*find_words_after_red(char *start);
void		ignore_signal(int n);
void		init_child_signals(void);
void		parent(t_global *global, char *path, int *pipe_fd, int num_pipe);
void		init_heredoc_signals(void);
void		sig_heredoc(int sig);

#endif
