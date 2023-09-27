/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:28:07 by amennad           #+#    #+#             */
/*   Updated: 2023/09/27 14:30:24 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <strings.h>

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

// void handle_signal(int signum, siginfo_t *info, void *context) {
//     static char received_char = 0;
//     static int bit_count = 0;

// 	(void)context;
// 	(void)info;

// 		usleep(100);
//     if (signum == SIGUSR1) {
//         received_char = (received_char << 1) | 1; // Ajouter un "1" à droite
//     } else if (signum == SIGUSR2) {
//         received_char <<= 1; // Décaler à gauche
//     }

//     bit_count++; // Incrémentez le compteur de bits

//
	// Affichez des informations de débogage pour vérifier l'accumulation des bits
//     printf("Bit %d : %d\n", bit_count, (signum == SIGUSR1) ? 1 : 0);

//     if (bit_count == 8) {
//         printf("Caractère reçu: %c\n", received_char);
//         received_char = 0; // Réinitialiser le caractère
//         bit_count = 0; // Réinitialiser le compteur de bits
//     }
// }

char	convert_to_character(char *bits)
{
	int i;
	int binary;
	int nbr;
	char c;

	i = 0;
	nbr = 0;
	binary = 1;
	while (i < 8)
	{
		if (bits[i] == '1')
			nbr += binary;
		binary *= 2;
		i++;
	}
	c = nbr;
	printf("Tableau binaire: %s\n", bits);
	printf("Nombre binaire: %d\n", nbr);
	printf("Caractère créé: %c\n", c);
	return (c);
}

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static char	received_bits[8];
	static int	bit_count = 0;
	char		caractere;

	/* The line `bit_count = 0;` is resetting the value of the `bit_count` variable to 0. This is done
	after a character has been received and processed, so that the program can start counting the bits
	of the next character from 0 again. */
	// bit_count = 0;
	(void)context;
	(void)info;
	usleep(100);
	if (signum == SIGUSR1)
	{
		received_bits[bit_count] = '1';
		bit_count++;
	}
	else if (signum == SIGUSR2)
	{
		received_bits[bit_count] = '0';
		bit_count++;
	}

	printf("Bit %d : %d\n", bit_count-1, (signum == SIGUSR1) ? 1 : 0);
	printf("Bit_count: %d\n", bit_count);
	if (bit_count == 8)
	{
		caractere = convert_to_character(received_bits);
		printf("Tableau binaire: %s\n", received_bits);
		printf("Caractère converti: %c\n", caractere);
		bit_count = 0;
	}
	// Parcourez le tableau et effectuez la conversion
}

int	main(void)
{
	struct sigaction	act;
	pid_t				pid;

	pid = getpid();
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART | SA_SIGINFO | SA_NODEFER;
	act.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_printf("Server PID: %d\n", pid);
	ft_printf("Listening...\n");
	if (sigaction(SIGUSR1, &act, NULL) < 0)
		ft_error("error sigaction");
	if (sigaction(SIGUSR2, &act, NULL) < 0)
		ft_error("error sigaction");
	while (1)
		continue ;
	return (0);
}
