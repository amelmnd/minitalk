/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:28:07 by amennad           #+#    #+#             */
/*   Updated: 2023/09/26 16:16:29 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <strings.h>

void	ft_sigusr1(int sig)
{
	(void)sig;
	ft_printf("SIGUSR1 received\n");
}

void	ft_sigusr2(int sig)
{
	(void)sig;
	ft_printf("SIGUSR2 received\n");
}


void  sig_handler (int sig)
{
	if (sig)
		printf("signal received\n");
}


int	main(void)
{
	struct sigaction act;
	sigset_t    signal_set;
	pid_t		pid;

	pid = getpid();
	sigemptyset(&signal_set);
	sigaddset(&signal_set, SIGINT);
	sigaddset(&signal_set, SIGQUIT);
	act.sa_mask = signal_set;
	act.sa_flags = SA_SIGINFO;
	act.sa_handler = &sig_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);

	ft_printf("Server PID: %d\n", pid);
	ft_printf("Listening...\n");


	while (1)
	{
		continue;
	}

	return (0);
}
