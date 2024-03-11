# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimic <msimic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 13:32:56 by msimic            #+#    #+#              #
#    Updated: 2023/12/29 17:46:21 by msimic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_UTILS = utils.c  # Add utils.c to the source files

OBJ_DIR = objs
OBJ_CLIENT = $(addprefix $(OBJ_DIR)/, $(SRC_CLIENT:.c=.o))
OBJ_SERVER = $(addprefix $(OBJ_DIR)/, $(SRC_SERVER:.c=.o))
OBJ_UTILS = $(addprefix $(OBJ_DIR)/, $(SRC_UTILS:.c=.o))  # Object file for utils.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(OBJ_DIR) client server

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

client: $(OBJ_CLIENT) $(OBJ_UTILS)  # Include OBJ_UTILS in the client target
	$(CC) $(CFLAGS) -o $@ $(OBJ_CLIENT) $(OBJ_UTILS)

server: $(OBJ_SERVER) $(OBJ_UTILS)  # Include OBJ_UTILS in the server target
	$(CC) $(CFLAGS) -o $@ $(OBJ_SERVER) $(OBJ_UTILS)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) client server

re: fclean all

.PHONY: all clean fclean re