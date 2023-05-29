/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_signals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:06:20 by mimoreir          #+#    #+#             */
/*   Updated: 2023/05/29 21:54:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

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

void	init_signals(void)
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
