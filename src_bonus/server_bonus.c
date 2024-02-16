/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:18:57 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/15 16:13:00 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*ft_strdup(char c)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*ft_strjoin_c(char *s1, char c)
{
	char			*newstr;
	unsigned int	i;

	if (!s1 && !c)
		return (NULL);
	if (!s1)
		return (ft_strdup(c));
	newstr = (char *)malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		newstr[i] = s1[i];
	newstr[i++] = c;
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}

void	bit_handler(int signum, siginfo_t *info, void *content)
{
	static char				*str = NULL;
	static unsigned char	c = 0;
	static int				nbit = 0;

	(void)content;
	if (signum == SIGUSR1)
		c = (c << 1) | 1;
	else
		c = c << 1;
	nbit++;
	if (nbit == 8)
	{
		nbit = 0;
		if (c == 0)
		{
			kill(info->si_pid, SIGUSR2);
			ft_putstr_fd(str, 1);
			free(str);
			write(1, "\n", 1);
			str = NULL;
		}
		else
			str = ft_strjoin_c(str, c);
		c = 0;
	}		
}

int	main(void)
{
	struct sigaction	new_sig;

	new_sig.sa_sigaction = &bit_handler;
	new_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &new_sig, NULL);
	sigaction(SIGUSR2, &new_sig, NULL);
	ft_putstr_fd("\nPID Number :\t", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\nserver en attente du message\n\n", 1);
	while (1)
	{
		pause();
	}
	return (0);
}
