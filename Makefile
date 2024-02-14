
all : client server

NAME = client

#COMPIL
CC = cc
CFLAGS = -Wall -Wextra -Werror 


#SOURCES
SRC =  	client.c\
		server.c\
		utils.c\
		client_bonus.c\
		server_bonus.c

#EXE
client : client.o utils.o
	$(CC) -o $@ client.o utils.o
	echo "\033[0;33m"client ok

server : server.o utils.o
	$(CC) -o $@ server.o utils.o
	echo "\033[0;33m"server ok

#retrait de minitalk.h
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< 

#BONUS

bonus : client_bonus server_bonus

client_bonus : client_bonus.o utils.o
	$(CC) -o $@ client_bonus.o utils.o
	echo "\033[0;33m"client_bonus ok

server_bonus : server_bonus.o utils.o
	$(CC) -o $@ server_bonus.o utils.o
	echo "\033[0;33m"server_bonus ok

#CLEANS
clean:
	rm -rf *.o
	
fclean: clean
	rm -rf client
	rm -rf server
	rm -rf client_bonus
	rm -rf server_bonus


re: fclean all

.PHONY: all clean fclean re
