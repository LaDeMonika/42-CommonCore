NAME = 	getnextline
SRC = get_next_line.c\
		get_next_line_utils.c
OBJDIR = ./objects/
OBJFILES = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJDIR), $(OBJFILES))

DEPT = get_next_line.h

CFLAGS = -Wall -Werror -Wextra -g
CC = cc
RM = rm -rf

.PHONY: clean fclean all

all: $(NAME)

$(OBJDIR)%.o: ./%.c $(DEPT)
		$(CC) $(CFLAGS) -MMD -MP $< -o $@ -c

$(OBJDIR):
		mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJDIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all