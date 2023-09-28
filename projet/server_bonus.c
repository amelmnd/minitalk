/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:10:59 by amennad           #+#    #+#             */
/*   Updated: 2023/09/28 12:30:53 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../include/libft/libft.h"

void	bin_to_char(int signum, char *c)
{
	if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signum == SIGUSR2)
		*c <<= 1;
}

void	create_str(char *c, char **message)
{
	char	*tmp;

	tmp = *message;
	if (!tmp)
		*message = ft_strdup(c);
	else
		*message = ft_strjoin(tmp, c);
	free(tmp);
}

pid_t	defined_pid(pid_t pid, siginfo_t *info)
{
	if (!pid && info->si_pid)
		pid = info->si_pid;
	return (pid);
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static char		c;
	static pid_t	pid;
	static int		i;
	static char		*message;

	(void)context;
	pid = defined_pid(pid, info);
	bin_to_char(signum, &c);
	if (++i == 8)
	{
		i = 0;
		if (c)
			create_str(&c, &message);
		else
		{
			ft_printf("%s\n", message);
			kill(info->si_pid, SIGUSR1);
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
	{
		ft_putstr_fd("Error sigaction", 2);
		exit(1);
	}
	if (sigaction(SIGUSR2, &sig, NULL) < 0)
	{
		ft_putstr_fd("Error sigaction", 2);
		exit(1);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
