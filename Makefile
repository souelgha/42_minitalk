
all : client server

#COMPIL
CC = cc
CFLAGS = -Wall -Wextra -Werror 

#EXE
client : emetteur_client.o
	$(CC) -o $@ emetteur_client.o
	echo "\033[2J\033[H""\033[0;33m"client ok

emetteur_client.o : emetteur_client.c minitalk.h
	$(CC) $(CFLAGS) -c emetteur_client.c

server : recepteur_server.o
	$(CC) -o $@ recepteur_server.o
	echo "\033[0;33m"server ok

recepteur_server.o : recepteur_server.c minitalk.h
	$(CC) $(CFLAGS) -c recepteur_server.c

#SOURCES
SRC =  	emetteur_client.c\
		recepteur_server.c

#CLEANS
clean:
	rm -rf *.o
	
fclean: clean
	rm -rf client
	rm -rf server


re: fclean all	

.PHONY: all clean fclean re
