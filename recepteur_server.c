/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recepteur_server.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:22:10 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/07 11:15:56 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void receiptmsg(int signum, siginfo_t *info, void *content) 
{
	(void)content;
	static char c = 0;
	static int nbite = 0;

	if (signum == SIGUSR1)
		{
			c = (c << 1) | 1;
		}
		else
			c = c << 1;
	nbite++;

}


int main(void) 
{

	printf("server <PID> = <%d>\n", getpid());
    printf("server <%d> en attente du message.\n", getpid());
	config_signal();
    while (1) 
	{
        pause();
    }
    return 0;
}
