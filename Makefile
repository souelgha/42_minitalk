
all : client server

#COMPIL
CC = cc
CFLAGS = -Wall -Wextra -Werror 

#EXE
client : client.o
	$(CC) -o $@ client.o
	echo "\033[2J\033[H""\033[0;33m"client ok

client.o : client.c minitalk.h
	$(CC) $(CFLAGS) -c client.c

server : server.o
	$(CC) -o $@ server.o
	echo "\033[0;33m"server ok

server.o : server.c minitalk.h
	$(CC) $(CFLAGS) -c server.c

#SOURCES
SRC =  	client.c\
		server.c

#CLEANS
clean:
	rm -rf *.o
	
fclean: clean
	rm -rf client
	rm -rf server


re: fclean all	

.PHONY: all clean fclean re
