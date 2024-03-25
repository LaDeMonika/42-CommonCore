# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimic <msimic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 11:41:51 by msimic            #+#    #+#              #
#    Updated: 2024/03/11 17:25:53 by msimic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c simulation.c routine.c utils_00.c utils_01.c utils_02.c

OBJ = $(SRC: .c=.o)

CFLAGS = -Wall -Werror -Wextra -g -pthread

all: $(NAME)

$(NAME): $(OBJ)
	@cc $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	@rm -f *.o
fclean:
	@rm -f $(NAME)
re:	fclean all

.PHONY:			all clean fclean re
