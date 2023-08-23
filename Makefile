NAME = pipex

SRC = pipex.c pipexec.c
OBJ = $(SRC:%.c=%.o)

CC = gcc
CFLAGS =  -Wall -Werror -Wextra

LIBFT = libtf/libft.a
LIBFTDIR = libft
LDFLAGS = -L./libft -lft 

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)
	
clean:
	rm -rf $(OBJ)
	@make -s clean -C $(LIBFTDIR)

fclean: clean
	rm -rf $(NAME)
	@make -s fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re