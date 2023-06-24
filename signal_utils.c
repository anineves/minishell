/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:20:34 by asousa-n          #+#    #+#             */
/*   Updated: 2023/06/24 14:23:29 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

void	sig_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		g_exit_status = 130;
		exit(130);
	}
	else if (sig == SIGQUIT)
	{
		ft_printf("minishell: Quit: (core dumped)");
		kill(0, SIGINT);
		g_exit_status = 131;
	}
}

void	init_heredoc_signals(void)
{
	struct sigaction	sigact;
	struct termios		termios_save;
	struct termios		termios_new;

	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_handler = sig_heredoc;
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
