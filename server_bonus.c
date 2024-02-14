/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:46:59 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/14 13:52:25 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk_bonus.h"

void	bit_handler(int signum, siginfo_t *info, void *content)
{
	(void)content;
	static unsigned char	c = 0;
	static int				nbit = 0;

	if (signum == SIGUSR1)
		c = (c << 1) | 1;
	else
		c = c << 1;
	nbit++;
	if (nbit == 8)
	{
		nbit = 0;
		if (c == 0)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		else
			ft_putchar_fd(c, 1);
		c = 0;
	}	
}

int	main(void)
{
	struct sigaction	new_sig;
	new_sig.sa_sigaction = &bit_handler;
	new_sig.sa_flags = SA_SIGINFO;
	
	sigaction(SIGUSR2, &new_sig, NULL);
	sigaction(SIGUSR1, &new_sig, NULL);
	ft_putstr_fd("\nPID server : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\nserver en attente du message\n\n", 1);
	
	while (1)
	{
		pause();
	}
	return (0);
}
