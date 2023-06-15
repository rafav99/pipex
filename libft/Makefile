NAME = libft.a
STR =  ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strchr.c ft_strrchr.c ft_strnstr.c 
MEM = ft_memcpy.c ft_memccpy.c  ft_memset.c ft_memchr.c ft_memcmp.c ft_memmove.c
IS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
MORE = ft_atoi.c ft_bzero.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c
NEW = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c
FILE = ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c
PRINTF = ft_printf.c printf_put.c printf_write.c printf_hex.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
EVERYC = $(STR) $(MEM) $(IS) $(MORE) $(NEW) $(FILE) $(PRINTF)

OBJS = $(EVERYC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra

BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		@ar rc $(NAME) $(OBJS)
bonus: $(BONUS)
		ar rc libft.a $(BONUS_OBJ)
clean:	
		rm -f $(OBJS) $(BONUS_OBJ)
fclean: clean
		rm -f libft.a
re: fclean all
