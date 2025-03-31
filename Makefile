CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = so_long
SRCS = so_long.c get_next_line.c libft.c parsing_util.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY : all clean  fclean re