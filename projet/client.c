/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:28:02 by amennad           #+#    #+#             */
/*   Updated: 2023/09/26 12:50:31 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "minitalk.h"


int main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Usage: ./client [server_pid] [message]\n");
		return (0);
	}
	ft_printf("I AM THE CLIENT\n");
	ft_printf("server pid: %d\n", ft_atoi(argv[1]));
	ft_printf("message: %s\n", argv[2]);

	kill(ft_atoi(argv[1]), SIGUSR1);
	return (0);
}