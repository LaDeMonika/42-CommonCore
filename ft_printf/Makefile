NAME = libftprintf.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(LIBFT_DIR)
AR = ar rcs
RM = rm -rf

OBJ = $(SRC:.c=.o)
SRC = ft_functions.c ft_printf.c ft_puthex.c ft_putptr.c

COLOUR_GREEN = '\033[0;32m'
COLOUR_RED = '\033[0;31m'
COLOUR_BLUE = '\033[0;34m'  
END_COLOUR = '\033[0m'

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $@ $^
	@echo $(COLOUR_GREEN)"🎉 libftprintf.a made successfully! 🎉"$(END_COLOUR)

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_DIR) clean
	@echo 🗑$(COLOUR_RED)" Delete all objects files."$(END_COLOUR)🗑

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	@echo 🗑 $(COLOUR_RED)" Delete everything."$(END_COLOUR)🗑

re: fclean all

.PHONY: all clean fclean re
