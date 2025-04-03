CC = cc
FLAGS = -g -Wall -Wextra -Werror -L /usr/include/minilibx-linux -lmlx -lXext -lX11
NAME = so_long
SRCS = so_long.c get_next_line.c libft.c parsing_util.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY : all clean  fclean re