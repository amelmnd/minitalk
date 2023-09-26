/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:28:07 by amennad           #+#    #+#             */
/*   Updated: 2023/09/26 12:49:00 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <strings.h>


int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	ft_printf("Listening...\n");
	printf("SIGUSR1: %d\n", SIGUSR1);
	printf("SIGUSR2: %d\n", SIGUSR2);
	while (1)
	{
		continue;
	}

	return (0);
}