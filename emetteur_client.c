/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emetteur_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:22:10 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/02 16:55:41 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
void	check_arg(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		printf("ERROR DE SAISIE :");
		printf("veuillez rentrer le PID du server et la chaine de caractere!\n ");
		return;
	}
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9') // ft_isdigit
		{
			printf("ERROR lors de l saisie du <PID>");
			return;
		}
		i++;
	}
	if (argv[2][0] == '\0')
	{
		printf("veuillez rentrer une chaine de caracteres non vide");
		return;
	}
}
void	sendmsg(char *str, pid_t pid) // conversion ok
{
	unsigned char n;
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
			{
				printf("1\t");
				kill(pid, SIGUSR1);
			}
			else
			{
				printf("0\t");
				kill(pid, SIGUSR2);
			}
			usleep(30);
			nbite--;
		}
		printf("\n");
		usleep(30);
		i++;
	}
}
void handle(int signum)
{
	static int received;

	received = 0;
	if (signum == SIGUSR1) 
	{
        printf("octet recu !\n");
		received++;
		usleep(100);
    }
	
}

// void	config_signal(void)
// {
// 	struct sigaction sa_sig;
// 	sigemptyset(&sa_sig.sa_mask);
// 	sa_sig.sa_sigaction = &sendmsg;
// 	sa_sig.sa_flags = SA_SIGINFO;
// 	if (sigaction(SIGUSR1, &sa_sig, NULL) == -1)
// 		printf("error_reception_SIGUSR1");
// 	if (sigaction(SIGUSR2, &sa_sig, NULL) == -1)
// 		printf("error_reception_SIGUSR2");
// }


int main(int argc, char **argv) 
{
	pid_t pid;
	(void)argc;
	check_arg(argc, argv);
	pid = atoi(argv[1]);
	signal(SIGUSR1, handle);
	signal(SIGUSR2, handle);
	//config_signal();
	//kill(pid, SIGUSR1);
	sendmsg(argv[2], pid);
	while(1)
	{
		pause();
	}
 	exit(EXIT_SUCCESS);
	return 0;
}
