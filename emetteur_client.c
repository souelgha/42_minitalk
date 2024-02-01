/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emetteur_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:22:10 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/01 17:36:03 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**** exemple pour s inspirer ******/
static void	check_arg(int argc, char **argv)
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
		if (argv[1][i] < '0' || argv[1][i] > '9') 
		{
			printf("ERROR lors de l saisie du <PID>");
			return;
		}
		i++;
	}
}

static void handler(int signum) 
{


}

void	config_signal(void)
{
	struct sigaction sa_sig;
	sa_sig.sa_sigaction = &handler;
	sa_sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_sig, NULL) == -1)
		handle_errors("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_sig, NULL) == -1)
		handle_errors("Failed to change SIGUSR2's behavior");
}

int main(int argc, char **argv) 
{
	int pid;
	check_arg(int argc, char **argv);
	pid = argv[i];

	while(1)
	{
		
	}
 
   return 0;
}
