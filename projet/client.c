/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:28:02 by amennad           #+#    #+#             */
/*   Updated: 2023/09/27 14:18:42 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "minitalk.h"

void ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}


int	ft_char_to_binary(char c, int pid)
{
	int bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		if ((c >> bit_index) & 1)
			{
                kill(pid, SIGUSR1);
                printf("Sent Signal SIGUSR1 (1)\n");
            }
		else
			{
                kill(pid, SIGUSR2);
                printf("Sent Signal SIGUSR2 (0)\n");
            }
		bit_index--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	static pid_t		server_pid;
	static char			*message;
	struct sigaction	act;
	static int			i;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [server_pid] [message]\n");
		return (0);
	}
	message = 0;
	i = 0;
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	sigemptyset(&act.sa_mask);
	// act.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	if (sigaction(SIGUSR1, &act, NULL) < 0)
		ft_error("error sigaction");
	if (sigaction(SIGUSR2, &act, NULL) < 0)
		ft_error("error sigaction");
	while (message[i])
	{
		printf("message[i]: %c\n", message[i]);
		ft_char_to_binary(message[i], server_pid);
		i++;
	}
	return (0);
}
