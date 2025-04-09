CC = cc
MLXDIR = -L/usr/include/minilibx-linux
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = $(MLXDIR) -lmlx -lXext -lX11
NAME = so_long
SRCS = ft_errors.c ft_moves.c ft_moves1.c ft_print.c get_next_line.c get_next_line2.c libft.c mlx_fun.c parsing_util.c parsing_util1.c parsing_utils2.c so_long.c

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(MLXFLAGS) -o $(NAME)

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY : all clean  fclean re so_long
