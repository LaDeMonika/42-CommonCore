# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimic <msimic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/25 18:18:21 by msimic            #+#    #+#              #
#    Updated: 2023/12/26 14:29:13 by msimic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER = push_swap.h

#Colors
GREEN = \033[0;92m

SRC_FILES = push_swap algorithm operations_00 operations_01 main \
	    sort utils_00 utils_01 utils_02

SRC = $(addsuffix .c, $(SRC_FILES))

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -g -o $(NAME)
	@echo "$(GREEN) $(NAME)!$(DEF_COLOR)"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re