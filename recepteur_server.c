/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recepteur_server.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:22:10 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/05 11:56:58 by sonouelg         ###   ########.fr       */
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
	printf("reception octet OK.\n");
//	printf("chart=%d\n", c);
	usleep(500);
	nbite++;
	kill(info->si_pid, SIGUSR2);	
	if (nbite == 8)
	{
		printf("%c\n", c);
		c = 0;
		nbite = 0;
	}
}

void	config_signal(void)
{
	struct sigaction sa_sig;
	sigemptyset(&sa_sig.sa_mask); 				// block les signaux quand le handler est appele
	sa_sig.sa_sigaction = &receiptmsg;
	sa_sig.sa_flags = SA_SIGINFO; 					// si le system est interrompu il redemarre en auto
	if (sigaction(SIGUSR1, &sa_sig, NULL) == -1)
		printf("error_reception_SIGUSR1");
	if (sigaction(SIGUSR2, &sa_sig, NULL) == -1)
		printf("error_reception_SIGUSR2");
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
