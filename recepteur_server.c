/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recepteur_server.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:22:10 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/02 16:54:38 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*void handler(int signum, siginfo_t *info, void *content) 
{
	pid_t pid;
	(void)content;
	pid = info->si_pid;
	int	i;
	i = 0;
	while (i < 8)
	{
		if (signum == SIGUSR1)
		{
			printf("reception signal OK.\n");
			sleep(1);
			kill(pid, SIGUSR1);
		}
		i++;
	}
	sleep(1);
	kill(pid, SIGUSR2);
	exit(EXIT_SUCCESS);
}*/

void receiptmsg(int signum, siginfo_t *info, void *content) 
{
	(void)content;
	int	nbite;
	static unsigned char c;
	nbite = 0;
	while (nbite < 7)
	{
		if (signum == SIGUSR1)
		{
			c = (c << 1) | 1;
		}
		else if (signum == SIGUSR2)
			c = c << 1;		
		printf("reception octet OK.\n");
		usleep(500);
		kill(info->si_pid, SIGUSR1);
		nbite++;
	}
	printf("char=%c\n", c);
	//kill(info->si_pid, SIGUSR1);
	//sleep(1);
	//kill(info->si_pid, SIGUSR2);
	exit(EXIT_SUCCESS);
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
