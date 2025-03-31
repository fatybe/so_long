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

typedef struct a
{
    int p;
    int e;
    int c;
} t_a;

typedef struct map
{
    int positionx_p;
    int positiony_p;
    int collectibles;
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
int ft_check(char **m);
void    check_map(char **m);
void position_p(char **m, t_map *map);

#endif
