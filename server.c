/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:07:39 by prossi            #+#    #+#             */
/*   Updated: 2024/02/13 17:36:40 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_handler(int signum)
{
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
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
	}		
}

int	main(void)
{
	signal(SIGUSR2, bit_handler);
	signal(SIGUSR1, bit_handler);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\nserver en attente du message\n\n", 1);
	while (1)
	{
		pause();
	}
	return (0);
}
