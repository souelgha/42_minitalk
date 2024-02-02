// static void	check_arg(int argc, char **argv)
// {
// 	int	i;

// 	if (argc != 3)
// 	{
// 		printf("ERROR DE SAISIE :");
// 		printf("veuillez rentrer le PID du server et la chaine de caractere!\n ");
// 		return;
// 	}
// 	i = 0;
// 	while (argv[1][i])
// 	{
// 		if (argv[1][i] < '0' || argv[1][i] > '9') // ft_isdigit
// 		{
// 			printf("ERROR lors de l saisie du <PID>");
// 			return;
// 		}
// 		i++;
// 	}
// 	if (argv[2][0] == '\0')
// 	{
// 		printf("veuillez rentrer une chaine de caracteres non vide");
// 		return;
// 	}
// }

#include "minitalk.h"
/*void handle_msg(int signum, siginfo_t *info, void *content) 
{
	(void)content;
	int	i;
	
	i = 0;
	if (signum == SIGUSR1) 
	{
        printf("confirmation Signal recu !\n");
		sleep(1);
		kill(info->si_pid, SIGUSR1);
    }
	if (signum == SIGUSR2)
		exit(EXIT_SUCCESS);
}*/

void	sendmsg( char *str, pid_t pid) // conversion ok
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
			usleep(10);
			nbite--;
		}
		printf("\n");
		usleep(10);
		i++;
	}
	//if (signum == SIGUSR2)
	exit(EXIT_SUCCESS);
}
void handler(int signum) 
{
	static int	i;
	static char c;
	int 		nbite;
	int 		i;

	nbite = 0;
	while (nbite < 7)
	{
		if (signum == SIGUSR1)
		{
			c = (c << 1) | 1;
		}
		else if (signum == SIGUSR2)
			c = c << 1;
		else 
			printf("error\n");
	//	n = n | 1;
	//	n = n >> 1;
		nbite++;

	}
}
int main(int argc, char **argv) 
{
	(void)argc;
	sendmsg(argv[2]);
 
   return 0;
}