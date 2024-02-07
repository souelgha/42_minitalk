/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emetteur_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:22:10 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/07 11:32:11 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int flag ;
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

void handle(int signum, siginfo_t *info, void *content)
{
	(void)content;
	(void)info;
	static int received = 0;	
	flag = 1;
	if (signum == SIGUSR2) //recu on recupere 2
		received++;
	else if (signum == SIGUSR1)
		printf("bites =%d\n", received); // fin on recupere 1
	
}

int main(int argc, char **argv)
{
	
	pid_t pid;
	struct sigaction sa_sig;  
	sigemptyset(&sa_sig.sa_mask);
	sa_sig.sa_flags = SA_SIGINFO;
	sa_sig.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa_sig, NULL);
	sigaction(SIGUSR2, &sa_sig, NULL);
	
	flag = 0;
	if(check_arg)
		return;
	
}
