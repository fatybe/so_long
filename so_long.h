#ifndef SO_LONG
#define SO_LONG

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include "/usr/include/minilibx-linux/mlx.h"


typedef struct s_data
{
    void *mlx;
    void *mlx_win;
    char **str;
    void *wall_image;
    void *exit_image;
    void *player_image;
    void *collectible_image;
    void *track_image;
    int moves;
    int c;
    int positionx_p;
    int positiony_p;
}t_map1;

typedef struct map
{
    int p;
    int e;
    int collectibles;
    int c;
    int position_e;
    char **map;
} t_map;
//parsing
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*readfd(int fd, char *buffer1);
char	*next_line(char *buffer);
char	*update(char *s);
char	*get_next_line(int fd);
void check_name(char **v);
char **ft_maps(char **v);
int is_rectangle(char **map);
int check_characters(char **map);
int check_wall(char **map);
int ft_check(t_map *a, char **m);
void    check_map(t_map *a, char **m);
void position_p(t_map1 *map);
void load_image(t_map1 *m);
void full_map(t_map1 *m);
void load_image(t_map1 *m);
void print_image(t_map1 *m);
#endif
