
all : client server

#COMPIL
CC = cc
CFLAGS = -Wall -Wextra -Werror 

#DIRECTORY
OBJ_FOLDER = obj 
BONUS_FOLDER = src_bonus
ORIG_FOLDER = src
HEADER_FOLDER = includes

#SOURCES
SRC =  	client.c\
		server.c\
		utils.c 

OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

obj/%.o: src/%.c
	@if [ ! -e $(OBJ_FOLDER) ]; then\
		mkdir -p $(OBJ_FOLDER);\
	fi
	@$(CC) $(CFLAGS) -I$(HEADER_FOLDER) -o $@ -c $< 

SRC_BONUS = client_bonus.c\
			server_bonus.c\
			utils_bonus.c 

OBJ_BONUS = $(patsubst src_bonus/%.c, obj/%.o, $(SRC))

obj/%.o: src_bonus/%.c
	@if [ ! -e $(OBJ_FOLDER) ]; then\
		mkdir -p $(OBJ_FOLDER);\
	fi
	@$(CC) $(CFLAGS) -I$(HEADER_FOLDER) -o $@ -c $< 

#MANDATORY
client : obj/client.o obj/utils.o
	@$(CC) $(CFLAGS) -I$(HEADER_FOLDER) $^ -o $@
	@echo "$(GREEN) client ok $(RESET)"

server : obj/server.o obj/utils.o
	@$(CC) $(CFLAGS) -I$(HEADER_FOLDER) $^ -o $@
	@echo "$(GREEN) server ok $(RESET)"


#BONUS

bonus : client_bonus server_bonus

client_bonus : obj/client_bonus.o obj/utils_bonus.o
	@$(CC) $(CFLAGS) -I$(HEADER_FOLDER) $^ -o $@
	@echo "$(GREEN) client_bonus ok $(RESET)"

server_bonus : obj/server_bonus.o obj/utils_bonus.o
	@$(CC) $(CFLAGS) -I$(HEADER_FOLDER) $^ -o $@
	@echo "$(GREEN) server_bonus ok $(RESET)"


#CLEANS
clean:
	rm -rf $(OBJ_FOLDER)
	echo "$(CLEAR) $(BLUE) cleaned $(RESET)"

	
fclean: clean
	rm -rf client
	rm -rf server
	rm -rf client_bonus
	rm -rf server_bonus
	echo "$(CLEAR) $(BLUE) cleaned $(RESET)"

re: fclean all	

.PHONY: all clean fclean re

.SILENT: clean fclean

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[38;5;97m
CLEAR = \033[2J\033[H
RESET = \033[0m
