/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emetteur_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:22:10 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/06 18:45:23 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_arg(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		printf("ERROR DE SAISIE :");
		printf("veuillez rentrer le PID du server ET la chaine de caractere!\n ");
		return (1);
	}
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9') // ft_isdigit
		{
			printf("ERROR lors de la saisie du <PID>");
			return (1);
		}
		i++;
	}
	if (argv[2][0] == '\0')
	{
		printf("veuillez rentrer une chaine de caracteres non vide");
		return (1);
	}
	return (0);
}

void	sendmsg(char *str, pid_t pid)
{
	 char n;
	int i;
	int nbite;

	i = 0;
	while (str[i])
	{
		n = str[i];
		nbite = 7;
		while(nbite >= 0)
		{
			if ((n >> nbite) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(700);
			nbite--;
		}
		usleep(700);
		i++;
	}
	nbite = 8;
	while (nbite--)
	{
		kill(pid, SIGUSR2);
		usleep(700);
	}
	
}

void handle(int signum, siginfo_t *info, void *content)
{
	(void)content;
	(void)info;
	static int received = 0;

	if (signum == SIGUSR2) 
        ++received;
	else
	{
		printf("re=%d\n", received);
		exit(0);
	}
	
	
}

void	config_signal(void)
{
	struct sigaction sa_sig;
	sigemptyset(&sa_sig.sa_mask);
	sa_sig.sa_sigaction = &handle;
	sa_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa_sig, NULL);
	sigaction(SIGUSR2, &sa_sig, NULL);
	if (sigaction(SIGUSR1, &sa_sig, NULL) == -1)
		printf("error_reception_SIGUSR1");
	if (sigaction(SIGUSR2, &sa_sig, NULL) == -1)
		printf("error_reception_SIGUSR2");
}

int main(int argc, char **argv) 
{
	pid_t pid;
	if (check_arg(argc, argv))
		return(1);
	pid = atoi(argv[1]);
	config_signal();
	printf("len=%ld\n", strlen(argv[2]));
	sendmsg(argv[2], pid);
	while(1)
	{
		pause();
	}
	
	return 0;
}