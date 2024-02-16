/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:07:39 by prossi            #+#    #+#             */
/*   Updated: 2024/02/15 12:17:06 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	bit_handler(int signum)
{
	static char				*str = NULL;
	static unsigned char	c = 0;
	static int				nbit = 0;

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
	signal(SIGUSR2, bit_handler);
	signal(SIGUSR1, bit_handler);
	ft_putstr_fd("\nPID Number :\t", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\nserver en attente du message\n\n", 1);
	while (1)
	{
		pause();
	}
	return (0);
}
