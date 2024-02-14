/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:33:48 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/14 13:51:31 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_bit(int pid, char *str, size_t len)
{
	int			shift;
	size_t		i;

	i = 0;
	while (i <= len)
	{
		shift = 7;
		while (shift >= 0)
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			shift--;
			usleep(400);
		}
		i++;
	}
}

void	handler(int signum)
{
	if (signum == SIGUSR2)
		ft_putstr_fd("message recu!\n", 1);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		signal(SIGUSR2, handler);
		signal(SIGUSR1, handler);
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_bit(pid, str, ft_strlen(str));
	}
	else
		ft_putstr_fd("\nMISSING STRING or WRONG <PID> FORMAT\n\n", 1);
}
