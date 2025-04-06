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
#include "/usr/include/minilibx-linux/minilibx-linux/mlx.h"


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
    void *door_player_image;
    int moves;
    int c;
    int positionx_p;
    int positiony_p;
    int height;
    int width;
}t_map1;

typedef struct map
{
    int p;
    int e;
    int collectibles;
    int position_e;
    char **map;
} t_map;
//parsing
int	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*readfd(int fd, char *buffer1);
char	*next_line(char *buffer);
char	*update(char *s);
char	*get_next_line(int fd);
void check_name(char **v);
char **ft_maps1(char **v);
char **ft_maps2(char **s);
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
void validate_inpute(t_map *m, int x, int y);
void flood_fill(t_map *m, int x, int y);
void full_map(t_map1 *m);
void load_image(t_map1 *m);
void print_image(t_map1 *m);
int ft_handler (int key_code, t_map1 *map);
void to_right(t_map1 *m);
void to_left(t_map1 *m);
void to_up(t_map1 *m);
void to_down(t_map1 *m);
void    ft_util(char c, t_map *a);
void free_arr(char **m);
void ft_initialize(t_map1 *m);
int ft_distroy(void *param);
void ft_error(void);
void ft_parsing (char **v, t_map1 *map1);
void ft_print(t_map1 *m);
#endif
