/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:33:48 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/16 09:59:25 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	check_arg(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		ft_putstr_fd(RED "\nMISSING STRING or <PID> \n\n", 1);
		return (1);
	}
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
		{
			ft_putstr_fd(RED "ERROR <PID> FORMAT\n", 1);
			return (1);
		}
		i++;
	}
	if (argv[2][0] == '\0')
	{
		ft_putstr_fd(RED "EMPTY STRING\n", 1);
		return (1);
	}
	return (0);
}

void	send_bit(int pid, char *str, size_t len)
{
	static int	sent = 0;
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
			sent++;
			shift--;
			usleep(400);
		}
		i++;
	}
}

void	handler(int signum)
{
	if (signum == SIGUSR2)
		ft_putstr_fd(GREEN "\nMessage recu par le server!\n", 1);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (check_arg(argc, argv))
		return (0);
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_bit(pid, str, ft_strlen(str));
	return (0);
}
