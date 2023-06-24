/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:03:45 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/24 14:46:50 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit_status;

char	**update_oldpwd(t_global *global)
{
	int		i;
	int		size;
	char	**new_copy_env;
	char	*new_path;

	i = 0;
	size = size_env(global->copy_env);
	new_path = ft_strjoin("OLDPWD=", global->old_path);
	new_copy_env = ft_calloc(size, sizeof(char *) + 1);
	while (global->copy_env[i])
	{
		if (ft_strncmp(global->copy_env[i], "OLDPWD", 6) == 0)
			new_copy_env[i] = ft_strdup(new_path);
		else
			new_copy_env[i] = ft_strdup(global->copy_env[i]);
		i++;
	}
	new_copy_env[i] = NULL;
	free_args(global->copy_env);
	free(new_path);
	return (new_copy_env);
}

char	**update_pwd(t_global *global)
{
	int		i;
	int		size;
	char	**new_copy_env;
	char	*new_path;
	char	pwd[PATH_MAX];

	i = 0;
	size = size_env(global->copy_env);
	new_path = ft_strjoin("PWD=", getcwd(pwd, PATH_MAX));
	new_copy_env = ft_calloc(size, sizeof(char *) + 1);
	while (global->copy_env[i])
	{
		if (ft_strncmp(global->copy_env[i], "PWD", 3) == 0)
			new_copy_env[i] = ft_strdup(new_path);
		else
			new_copy_env[i] = ft_strdup(global->copy_env[i]);
		i++;
	}
	new_copy_env[i] = NULL;
	free_args(global->copy_env);
	free(new_path);
	return (new_copy_env);
}

void	change_dir(t_global *global, char *next_path)
{
	char	*path;

	path = getcwd(NULL, 0);
	free(global->old_path);
	global->old_path = ft_strdup(path);
	free(path);
	if (chdir(next_path) == 0)
		g_exit_status = 0;
	else
	{
		printf("bash: cd: %s: No such file or directory\n", global->args[1]);
		g_exit_status = 1;
	}
	global->copy_env = update_pwd(global);
	global->copy_env = update_oldpwd(global);
}

int	ft_old_path(t_global *global)
{
	if ((ft_strcmp(global->args[1], "-") == 0))
	{
		ft_putstr_fd(global->old_path, global->fd_output);
		ft_putstr_fd("\n", global->fd_output);
		if (chdir(global->old_path) == 0)
			g_exit_status = 0;
		return (1);
	}
	return (0);
}

void	ft_cd(t_global *global)
{
	char	*next_path;

	if (global->shell->flag == HEREDOC || global->shell->flag == RD_IN)
		return ;
	next_path = NULL;
	if (global->args[1] && global->args[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", global->fd_output);
		g_exit_status = 1;
		return ;
	}
	if (global->args[1])
	{
		if (ft_old_path(global) == 1)
			return ;
	}
	next_path = global->args[1];
	if ((!global->args[1]) || (ft_strcmp(global->args[1], "~") == 0))
		next_path = getenv("HOME");
	change_dir(global, next_path);
}
