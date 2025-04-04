/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:27:02 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/04 18:20:49 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_util(char c, t_map *a)
{
    if (c == 'P')
        a->p++;
    if (c == 'E')
        a->e++;
    if (c == 'C')
        a->collectibles++;
}
int ft_check(t_map *a, char **m)
{
    int i;
    int j;
    
    i = 0;
    a->p = 0;
    a->e = 0;
    a->collectibles = 0;
    while (m[i])
    {
        j = 0;
        while (m[i][j])
        {
            ft_util(m[i][j], a);
            j++;
        }
        i++;
    }
    if (a->p != 1 || a->e != 1 || a->collectibles < 1)
        return (1);
    return (0);
}
void    check_map(t_map *map, char **m)
{
    if (is_rectangle(m) == 1)
        write(2, "invalide map\n", 14);
    if (check_characters(m) == 1)
        write(2, "invalide map\n", 14);
    if (check_wall(m) == 1)
        write(2, "invalide map\n", 14);
    if (ft_check(map, m) == 1)
        write(2, "invalide map\n", 14);
}
void position_p(t_map1 *map)
{
    int i;
    int j;
     
    map->positionx_p = 0;
    map->positiony_p = 0;
    map->c = 0;
    i = 0;
    map->height = 0;
    map->width = 0;
    while (map->str[i])
    {
        j = 0;
        while (map->str[i][j])
        {
            
            if (map->str[i][j] == 'P')
            {
                map->positionx_p = i;
                map->positiony_p = j;
            }
            if (map->str[i][j] == 'C')
                map->c++;
            j++;
        }
        i++;
    }
    map->height = j;
    map->width = i;
}

void flood_fill(t_map *m, char **str, int x, int y)
{
    if (x > 0 || y > 0 || str[x][y] == '1' || str[x][y] == 'V')
        return ;
    if (str[x][y] == 'E')
        m->position_e += 1;
    if (str[x][y] == '0' || str[x][y] == 'C' || str[x][y] == 'P')
    {
        str[x][y] = 'V';
        if (str[x][y] == 'C')
            m->c++;
    }
    flood_fill(m, str, x + 1, y);
    flood_fill(m, str, x - 1, y);
    flood_fill(m, str, x, y + 1);
    flood_fill(m, str, x, y - 1);
}
void validate_inpute(t_map *m, int x, int y, int total_collectible)
{
    m->position_e = 0;
    m->c = 0;
    flood_fill(m, m->map, x, y);
    printf("%d\n",m->position_e);
    printf("colle is %d\n", m->c);
    // int i = 0;
    // while (m->map[i])
    // {
    //     int j = 0;
    //     while (m->map[i][j])
    //     {
    //          printf("%c",m->map[i][j]);
    //         j++;
    //     }
    //     printf("\n");
    //     i++;
    // }
    // if (position_e == 1 && collectible != total_collectible)
    // {
    //     write (2, "collectible doesn't taken\n", 27);
    //     exit (0);
    // }
    // if (position_e == 0)
    // {
    //     write (2, "E dosn't exit\n", 15);
    //     exit (0);
    // }
}

void full_map(t_map1 *m)
{
    load_image(m);
    print_image(m);
}
void load_image(t_map1 *m)
{
    int width = 64;
    int height = 64;
    m->player_image = mlx_xpm_file_to_image(m->mlx, "/home/fbenjama/Desktop/so_long/images/player.xpm", &width, &height);
    m->track_image = mlx_xpm_file_to_image(m->mlx, "/home/fbenjama/Desktop/so_long/images/track.xpm", &width, &height);
    m->wall_image = mlx_xpm_file_to_image(m->mlx, "/home/fbenjama/Desktop/so_long/images/water.xpm", &width, &height);
    m->exit_image = mlx_xpm_file_to_image(m->mlx, "/home/fbenjama/Desktop/so_long/images/door.xpm", &width, &height);
    m->collectible_image = mlx_xpm_file_to_image(m->mlx, "/home/fbenjama/Desktop/so_long/images/collectible.xpm", &width, &height);
    m->door_player_image = mlx_xpm_file_to_image(m->mlx, "/home/fbenjama/Desktop/so_long/images/player+door.xpm", &width, &height);
}
void print_image(t_map1 *m)
{
    int i = 0;
    int j;
    while (m->str[i])
    {
        j = 0;
        while (m->str[i][j])
        {
            if (m->str[i][j] == 'P')
                mlx_put_image_to_window(m->mlx, m->mlx_win, m->player_image, j * 64, i * 64);
            if (m->str[i][j] == '0')
                mlx_put_image_to_window(m->mlx, m->mlx_win, m->track_image, j *64, i * 64);
            if (m->str[i][j] == '1')
                mlx_put_image_to_window(m->mlx, m->mlx_win, m->wall_image, j *64, i * 64);
            if (m->str[i][j] == 'E')
                mlx_put_image_to_window(m->mlx, m->mlx_win, m->exit_image, j * 64, i * 64);
            if (m->str[i][j] == 'C')
                mlx_put_image_to_window(m->mlx, m->mlx_win, m->collectible_image, j * 64, i * 64);
            if (m->str[i][j] == 'A')
                mlx_put_image_to_window(m->mlx, m->mlx_win, m->door_player_image, j * 64, i * 64);
            j++;
        }
        i++;
    }
}

void to_right(t_map1 *m)
{
    int i = m->positionx_p;
    int j = m->positiony_p;
    if (m->str[i][j + 1] != 'A' && m->str[i][j + 1] == 'C')
    {
        m->str[i][j] = '0';
        m->str[i][j + 1] = 'P';
        m->positiony_p++;
        m->c--;
    }
    if (m->str[i][j + 1] != 'A' && m->str[i][j + 1] == '0')
    {
        m->str[i][j] = '0';
        m->str[i][j + 1] = 'P';
        m->positiony_p++;
    }
    if (m->str[i][j + 1] != 'A' && m->str[i][j + 1] == 'E')
    {
        if (m->c == 0)
            exit(0);
        else if (m->c != 0)
        {
            m->str[i][j] = '0';
            m->str[i][j + 1] = 'A';
        }
    }
    if (m->str[i][j] == 'A' && m->str[i][j + 1] != '1')
    {
        if (m->str[i][j + 1] == '0')
        {
            m->str[i][j] = 'E';
            m->str[i][j + 1] = 'P'; 
        }
    }
}
void to_left(t_map1 *m)
{
    int i = m->positionx_p;
    int j = m->positiony_p;
    if (m->str[i][j - 1] != 'A' && m->str[i][j - 1] == 'C')
    {
        m->str[i][j] = '0';
        m->str[i][j -1] = 'P';
        m->positiony_p--;
        m->c--;
    }
    if (m->str[i][j - 1] != 'A' && m->str[i][j - 1] == '0')
    {
        m->str[i][j] = '0';
        m->str[i][j - 1] = 'P';
        m->positiony_p--;
    }
    if (m->str[i][j - 1] != 'A' && m->str[i][j - 1] == 'E')
    {
        if (m->c == 0)
            exit(0);
        else if (m->c != 0)
        {
            m->str[i][j] = '0';
            m->str[i][j - 1] = 'A';
        } 
    }
    if (m->str[i][j] == 'A' && m->str[i][j - 1] != '1')
    {
        if (m->str[i][j - 1] == '0')
        {
            m->str[i][j] = 'E';
            m->str[i][j - 1] = 'P'; 
        }
    }
}
void to_up(t_map1 *m)
{
    int i = m->positionx_p;
    int j = m->positiony_p;
    if (m->str[i - 1][j] != 'A' && m->str[i - 1][j] == 'C')
    {
        m->str[i][j] = '0';
        m->str[i - 1][j] = 'P';
        m->positionx_p--;
        m->c--;
    }
    if (m->str[i - 1][j] != 'A' && m->str[i - 1][j] == '0')
    {
        m->str[i][j] = '0';
        m->str[i - 1][j] = 'P';
        m->positionx_p--;
    }
    if (m->str[i - 1][j] != 'A' && m->str[i - 1][j] == 'E')
    {
        if (m->c == 0)
            exit(0);
        else if (m->c != 0)
        {
            m->str[i][j] = '0';
            m->str[i - 1][j] = 'A';
        }
    }
    if (m->str[i][j] == 'A' && m->str[i - 1][j] != '1')
    {
        if (m->str[i - 1][j] == '0')
        {
            m->str[i][j] = 'E';
            m->str[i - 1][j] = 'P'; 
        }
    }
}
void to_down(t_map1 *m)
{
    int i = m->positionx_p;
    int j = m->positiony_p;
    if (m->str[i + 1][j] != 'A' && m->str[i + 1][j] == 'C')
    {
        m->str[i][j] = '0';
        m->str[i + 1][j] = 'P';
        m->positionx_p++;
        m->c--;
    }
    if (m->str[i + 1][j] != 'A' && m->str[i + 1][j] == '0')
    {
        m->str[i][j] = '0';
        m->str[i + 1][j] = 'P';
        m->positionx_p++;
    }
    if (m->str[i + 1][j] != 'A' && m->str[i + 1][j] == 'E')
    {
        if (m->c == 0)
            exit(0);
        else if (m->c != 0)
        {
            m->str[i][j] = '0';
            m->str[i + 1][j] = 'A';
        }
    }
    if (m->str[i][j] == 'A' && m->str[i + 1][j] != '1')
    {
        if (m->str[i + 1][j] == '0')
        {
            m->str[i][j] = 'E';
            m->str[i + 1][j] = 'P'; 
        }
    }
}
int ft_distroy(void *param)
{
    t_map1 *map = (t_map1 *)param;
    mlx_destroy_image(map->mlx, map->wall_image);
    mlx_destroy_image(map->mlx, map->exit_image);
    mlx_destroy_image(map->mlx, map->player_image);
    mlx_destroy_image(map->mlx, map->collectible_image);
    mlx_destroy_image(map->mlx, map->track_image);
    mlx_destroy_window(map->mlx, map->mlx_win);
    mlx_destroy_display(map->mlx);
    free(map->mlx);
    //free_arr(map->str);
    exit(0);
    return (0);
}
int ft_handler (int key_code, t_map1 *map)
{
    void *d;
    map->moves = 0;
    if (key_code == 100)
        to_right(map);
    if (key_code == 97)
        to_left(map);
    if (key_code == 119)
        to_up(map);
    if (key_code == 115)
        to_down(map);
    if (key_code == 65307)
        exit(0);
        
    print_image(map);
    return (0);
}

void free_arr(char **m)
{
    int i = 0;
    while (m[i])
    {
        free(m[i]);
        i++;
    }
    free(m[i]);
}
int main(int c, char **v)
{
    t_map   map;
    t_map1  map1;
    char **m;
    check_name(v);
    m = ft_maps(v);
    free_arr(m);
    map.map = m;
    map1.str = m;
    check_map(&map, m);
    position_p(&map1);
    //validate_inpute(&map, map.positionx_p, map.positiony_p, map.collectibles);
    map1.mlx = mlx_init();
    if (!map1.mlx)
        return (0);
    map1.mlx_win = mlx_new_window(map1.mlx, map1.height *64, map1.width * 64, "so_long");
    if (!map1.mlx_win)
        return (0);
    full_map(&map1);
    mlx_key_hook(map1.mlx_win, ft_handler, &map1);
    mlx_hook(map1.mlx_win, 17, 0, ft_distroy, &map1);
    mlx_loop(map1.mlx);
}
