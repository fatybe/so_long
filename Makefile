CC = cc
MLXDIR = -L/usr/include/minilibx-linux
CFLAGS = -g -Wall -Wextra -Werror
MLXFLAGS = $(MLXDIR) -lmlx -lXext -lX11
NAME = so_long
SRCS = so_long.c get_next_line.c libft.c parsing_util.c ft_errors.c ft_moves.c ft_print.c parsing_util1.c parsing_utils2.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY : all clean  fclean re so_long