/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:01:17 by tlefebvr          #+#    #+#             */
/*   Updated: 2022/03/07 18:00:19 by tlefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"
#include "minitalk.h"

static void	action(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	(void)info;
	if (!g_mes_print.top_bit)
	{
		g_mes_print.top_bit = 1 << 6;
		++(g_mes_print.top_byte);
	}
	g_mes_print.message[g_mes_print.top_byte] += g_mes_print.top_bit;
	g_mes_print.top_bit >>= 1;
	if (g_mes_print.top_byte == BUFFSIZE - 2 && !g_mes_print.top_bit)
		g_mes_print.buff_overflow = TRUE;
}

void	nullbit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (!g_mes_print.top_bit)
	{
		g_mes_print.top_bit = 1 << 6;
		++(g_mes_print.top_byte);
	}
	g_mes_print.top_bit >>= 1;
	if (g_mes_print.top_byte == BUFFSIZE - 2 && !g_mes_print.top_bit)
		g_mes_print.buff_overflow = TRUE;
	else if (!g_mes_print.message[g_mes_print.top_byte]
		&& !g_mes_print.top_bit)
	{
		g_mes_print.all_receive = TRUE;
		kill(info->si_pid, SIGUSR1);
	}
}

_Bool	main_handler(void)
{
	while (1)
	{
		pause();
		if (g_mes_print.all_receive || g_mes_print.buff_overflow)
		{
			ft_putstr_fd(g_mes_print.message, 1);
			ft_bzero(g_mes_print.message, BUFFSIZE);
			g_mes_print.top_byte = 0;
			g_mes_print.top_bit = 1 << 6;
			if (g_mes_print.all_receive)
				write(1, "\n", 1);
			g_mes_print.all_receive = FALSE;
			g_mes_print.buff_overflow = FALSE;
		}
	}
	return (TRUE);
}

int	main(void)
{
	struct sigaction	active_act;
	struct sigaction	null_act;

	active_act.sa_sigaction = action;
	null_act.sa_sigaction = nullbit;
	active_act.sa_flags = SA_SIGINFO;
	null_act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &active_act, NULL) != 0 )
		ft_putstr_fd("Error\n", 1);
	if (sigaction(SIGUSR2, &null_act, NULL) != 0 )
		ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	main_handler();
}
