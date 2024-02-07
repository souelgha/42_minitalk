/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:07:48 by prossi            #+#    #+#             */
/*   Updated: 2024/02/07 17:31:53 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, char *str, size_t len)
{
	static int sent = 0;
	int		shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 7;
		while (shift >= 0 )
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			sent++;
			shift--;
			usleep(500);
		}
		i++;
	}
	printf("sent=%d\n", sent);
}
void handler(int signum)
{
	if (signum == SIGUSR1 || signum == SIGUSR2)
		printf("signal recu!\n");
}
int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		signal(SIGUSR2, handler);
		signal(SIGUSR1, handler);
		pid = atoi(argv[1]);
		str = argv[2];
		send_bit(pid, str, strlen(str));
	}
	else
		printf("\nYOU EITHER LEFT IT BLANK OR ARE DOING MORE THAN 1 WORD\n\n");
}