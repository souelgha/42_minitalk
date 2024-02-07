/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:07:39 by prossi            #+#    #+#             */
/*   Updated: 2024/02/07 17:27:53 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_handler(int signum)
{
	static unsigned char c = 0;
	static int nbit = 0;

	if (signum == SIGUSR1)
		c = (c << 1) | 1;
	else
		c = c << 1;
	nbit++;
	if (nbit == 8)
	{
		nbit = 0;
		if(c == 0)
			printf("\n");
		else
			printf("%c", c);	
		c = 0;
	}
		
}

int	main(void)
{
	signal(SIGUSR2, bit_handler);
	signal(SIGUSR1, bit_handler);
	printf("server <PID> = <%d>\n", getpid());
    printf("server <%d> en attente du message.\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}