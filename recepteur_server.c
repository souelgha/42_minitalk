/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recepteur_server.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:22:10 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/06 17:54:01 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void receiptmsg(int signum, siginfo_t *info, void *content) 
{
	(void)content;
	static char c = 0;
	static int nbite = 0;
	static pid_t pid = 0;

	if (!pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c = (c << 1) | 1;
	else
		c = c << 1;
	nbite++;		
	if (nbite == 8)
	{
		nbite = 0;
		if (!c)
		{
			
			kill(pid, SIGUSR1);
			pid = 0;
			write(1, "\n", 1);
			return;
		}
		write(1, &c, 1);		
		c = 0;
		kill(pid, SIGUSR2);
	}
	
}

void	config_signal(void)
{
	struct sigaction sa_sig;
	sigemptyset(&sa_sig.sa_mask); 				
	sa_sig.sa_sigaction = &receiptmsg;
	sa_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa_sig, NULL);
	sigaction(SIGUSR2, &sa_sig, NULL);		
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
