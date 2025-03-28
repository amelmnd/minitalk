/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:28:02 by amennad           #+#    #+#             */
/*   Updated: 2023/09/28 12:30:44 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../include/libft/libft.h"

static int	g_get_signal;

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	sig_handler(int signum)
{
	(void)signum;
	g_get_signal = 1;
}

int	ft_char_to_binary(char c, int pid)
{
	int	try;
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		try = 0;
		if ((c >> bit_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_get_signal)
		{
			if (try == 50)
			{
				ft_printf("No answer from server.\n");
				exit(1);
			}
			try++;
			usleep(100);
		}
		g_get_signal = 0;
		bit_index--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;
	static pid_t		server_pid;
	static int			i;

	if (argc != 3)
		ft_error("Usage: ./client [server_pid] [message]\n");
	server_pid = ft_atoi(argv[1]);
	i = 0;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_RESTART | SA_SIGINFO;
	sig.sa_handler = &sig_handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	if (sigaction(SIGUSR1, &sig, NULL) < 0)
		ft_error("Error sigaction");
	if (sigaction(SIGUSR2, &sig, NULL) < 0)
		ft_error("Error sigaction");
	while (argv[2][i])
	{
		ft_char_to_binary(argv[2][i], server_pid);
		i++;
	}
	ft_char_to_binary('\0', server_pid);
	return (0);
}
