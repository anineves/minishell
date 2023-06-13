/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_signals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:06:20 by mimoreir          #+#    #+#             */
/*   Updated: 2023/06/13 13:50:26 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

void	sig_int(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		g_exit_status = 130;
	}
}

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_status = 130;
	}
}

void	sig_quit(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_printf("minishell: Quit: (core dumped)");
		kill(0, SIGINT);
		g_exit_status = 131;
	}
}
void	init_signals()
{
	struct sigaction	sigact;
	struct termios		termios_save;
	struct termios		termios_new;

	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_handler = sig_handler;
	sigaction(SIGINT, &sigact, NULL);
	sigaction(SIGQUIT, &sigact, NULL);
	if (tcgetattr(0, &termios_save) == -1)
	{
		perror("Error EOF signal\n");
		exit(1);
	}
	termios_new = termios_save;
	termios_new.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, 0, &termios_new) == -1)
	{
		perror("Error EOF signal\n");
		exit(1);
	}
}
