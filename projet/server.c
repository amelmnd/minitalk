/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:28:07 by amennad           #+#    #+#             */
/*   Updated: 2023/09/28 11:14:58 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <strings.h>
#include <time.h>       // for time()


void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	bin_to_char(int signum, char *c)
{
	if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signum == SIGUSR2)
		*c <<= 1;
}

void	create_str(char *c, char **message)
{
	char *tmp;

	tmp = *message;
	if (!tmp)
		*message = ft_strdup(c);
	else
		*message = ft_strjoin(tmp, c);
	free(tmp);
}


void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static	char	c;
	static	pid_t	pid;
	static	int		i;
	static char	*message;

	(void)context;
	if (!pid && info->si_pid)
		pid = info->si_pid;
	bin_to_char(signum, &c);

	if (++i == 8)
	{
		i = 0;

		if (c)
		{
			create_str(&c, &message);
		}
		else
		{
			ft_printf("%s\n", message);
			kill(pid, SIGUSR1);
			pid = 0;
			free(message);
			message = NULL;
			return ;
		}
		c = 0;
	}
	kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sig;
	ft_printf("Server PID: %d\n", getpid());
	ft_printf("Listening...\n");
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_RESTART | SA_SIGINFO;
	sig.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	if (sigaction(SIGUSR1, &sig, NULL) < 0)
		ft_error("error sigaction");
	if (sigaction(SIGUSR2, &sig, NULL) < 0)
		ft_error("error sigaction");
	while (1)
	{
		pause() ;
	}
	return (0);
}
