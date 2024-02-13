
all : client server

#COMPIL
CC = cc
CFLAGS = -Wall -Wextra -Werror 


#SOURCES
SRC =  	client.c\
		server.c\
		utils.c

#EXE
client : client.o utils.o
	$(CC) -o $@ client.o utils.o
	echo "\033[0;33m"client ok

server : server.o utils.o
	$(CC) -o $@ server.o utils.o
	echo "\033[0;33m"server ok

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -o $@ -c $< 

#CLEANS
clean:
	rm -rf *.o
	
fclean: clean
	rm -rf client
	rm -rf server


re: fclean all	

.PHONY: all clean fclean re
