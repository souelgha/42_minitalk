#include "minitalk.h"
/** test fonction lecture des bins***/
void	sendstr(char *str)
{
	unsigned char n;
	int i;
	int nbite;

	i = 0;
	while(str[i])
	{
		n = str[i];
		nbite = 7;
		while(nbite >= 0)
		{
			nbite = (n & 0b10000000);
			if (nbite)
				printf("1\t");
			else
				printf("0\t");
			n = n << 1;
			i--;
		}
	}
}




int main (int argc, char **argv)
{
	/**** check l etat des octets*/
	unsigned char c;
	int	i;
	
	
	i = 0;
	c = argv[1][i];
	sendoctet(c);
	printf("\n");

	return (0);

}
	
