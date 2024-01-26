/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:06:29 by tlefebvr          #+#    #+#             */
/*   Updated: 2022/03/07 13:58:34 by tlefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <zconf.h>
#include "libft/libft.h"

void	send_char(int pid, unsigned char byte)
{
	uint8_t	counter;

	counter = 1 << 6;
	while (counter)
	{
		if (byte & counter)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_putstr_fd("Mauvais PID\n", 1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_putstr_fd("Mauvais PID\n", 1);
		}
		counter >>= 1;
		usleep(600);
	}	
}

void	main_handler(char *str_pid, char *message )
{
	int	pid;

	pid = ft_atoi(str_pid);
	while (*message)
	{
		send_char(pid, *message);
		++message;
	}
	send_char(pid, *message);
}

void	succes(int sig)
{
	(void)sig;
	ft_putstr_fd("les donnees ont ete reçues.\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		ft_putstr_fd("Envois :", 1);
	signal(SIGUSR1, succes);
	main_handler(argv[1], argv[2]);
	return (0);
}
