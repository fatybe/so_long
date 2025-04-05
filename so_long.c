/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:27:02 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/05 01:39:46 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void flood_fill(t_map *m, int x, int y)
{
    if (x < 0 || y < 0 || m->map[x][y] == '1' || m->map[x][y] == 'V')
        return ;
    if (m->map[x][y] == 'E')
    {
        m->position_e += 1;
        m->map[x][y] = 'V';
    } 
    if (m->map[x][y] == '0' || m->map[x][y] == 'C' || m->map[x][y] == 'P')
    {
        if (m->map[x][y] == 'C')
            m->collectibles--;
        m->map[x][y] = 'V';
    }
    flood_fill(m, x + 1, y);
    flood_fill(m, x - 1, y);
    flood_fill(m, x, y + 1);
    flood_fill(m, x, y - 1);
}
void validate_inpute(t_map *m, int x, int y, int total_collectible)
{
    m->position_e = 0;
    
    flood_fill(m, x, y);
    if (m->position_e == 1 && m->collectibles > 0)
    {
        write (2, "collectible doesn't taken\n", 27);
        free_arr(m->map);
        exit (0);
    }
    if (m->position_e == 0)
    {
        write (2, "E dosn't exit\n", 15);
        free_arr(m->map);
        exit (0);
    }
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
    // m->door_player_image = mlx_xpm_file_to_image(m->mlx, "/home/fbenjama/Desktop/so_long/images/player+door.xpm", &width, &height);
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
            // if (m->str[i][j] == 'A')
            //     mlx_put_image_to_window(m->mlx, m->mlx_win, m->door_player_image, j * 64, i * 64);
            j++;
        }
        i++;
    }
}

void to_right(t_map1 *m)
{
    int i = m->positionx_p;
    int j = m->positiony_p;
    if (m->str[i][j + 1] == 'C')
    {
        m->str[i][j] = '0';
        m->str[i][j + 1] = 'P';
        m->positiony_p++;
        m->c--;
    }
    if (m->str[i][j + 1] == '0')
    {
        m->str[i][j] = '0';
        m->str[i][j + 1] = 'P';
        m->positiony_p++;
    }
    if (m->str[i][j + 1] == 'E')
    {
        if (m->c == 0)
            exit(0);
        // else if (m->c != 0)
        // {
        //     m->str[i][j] = '0';
        //     m->str[i][j + 1] = 'A';
        // }
    }
    // if (m->str[i][j] == 'A' && m->str[i][j + 1] != '1')
    // {
    //     if (m->str[i][j + 1] == '0')
    //     {
    //         m->str[i][j] = 'E';
    //         m->str[i][j + 1] = 'P'; 
    //     }
    // }
}
void to_left(t_map1 *m)
{
    int i = m->positionx_p;
    int j = m->positiony_p;
    if (m->str[i][j - 1] == 'C')
    {
        m->str[i][j] = '0';
        m->str[i][j -1] = 'P';
        m->positiony_p--;
        m->c--;
    }
    if (m->str[i][j - 1] == '0')
    {
        m->str[i][j] = '0';
        m->str[i][j - 1] = 'P';
        m->positiony_p--;
    }
    if(m->str[i][j - 1] == 'E')
    {
        if (m->c == 0)
            exit(0);
        // else if (m->c != 0)
        // {
        //     m->str[i][j] = '0';
        //     m->str[i][j - 1] = 'A';
        // } 
    }
    // if (m->str[i][j] == 'A' && m->str[i][j - 1] != '1')
    // {
    //     if (m->str[i][j - 1] == '0')
    //     {
    //         m->str[i][j] = 'E';
    //         m->str[i][j - 1] = 'P'; 
    //     }
    // }
}
void to_up(t_map1 *m)
{
    int i = m->positionx_p;
    int j = m->positiony_p;
    if (m->str[i - 1][j] == 'C')
    {
        m->str[i][j] = '0';
        m->str[i - 1][j] = 'P';
        m->positionx_p--;
        m->c--;
    }
    if (m->str[i - 1][j] == '0')
    {
        m->str[i][j] = '0';
        m->str[i - 1][j] = 'P';
        m->positionx_p--;
    }
    if (m->str[i - 1][j] == 'E')
    {
        if (m->c == 0)
            exit(0);
        // else if (m->c != 0)
        // {
        //     m->str[i][j] = '0';
        //     m->str[i - 1][j] = 'A';
        // }
    }
    // if (m->str[i][j] == 'A' && m->str[i - 1][j] != '1')
    // {
    //     if (m->str[i - 1][j] == '0')
    //     {
    //         m->str[i][j] = 'E';
    //         m->str[i - 1][j] = 'P'; 
    //     }
    // }
}
void to_down(t_map1 *m)
{
    int i = m->positionx_p;
    int j = m->positiony_p;
    if (m->str[i + 1][j] == 'C')
    {
        m->str[i][j] = '0';
        m->str[i + 1][j] = 'P';
        m->positionx_p++;
        m->c--;
    }
    if (m->str[i + 1][j] == '0')
    {
        m->str[i][j] = '0';
        m->str[i + 1][j] = 'P';
        m->positionx_p++;
    }
    if (m->str[i + 1][j] == 'E')
    {
        if (m->c == 0)
            exit(0);
        // else if (m->c != 0)
        // {
        //     m->str[i][j] = '0';
        //     m->str[i + 1][j] = 'A';
        // }
    }
    // if (m->str[i][j] == 'A' && m->str[i + 1][j] != '1')
    // {
    //     if (m->str[i + 1][j] == '0')
    //     {
    //         m->str[i][j] = 'E';
    //         m->str[i + 1][j] = 'P'; 
    //     }
    // }
}
void free_arr(char **m)
{
    int i = 0;
    while (m[i])
    {
        free(m[i]);
        i++;
    }
    free(m);
}
int ft_distroy(void *param)
{
    t_map1 *map = (t_map1 *)param;
    mlx_destroy_image(map->mlx, map->wall_image);
    mlx_destroy_image(map->mlx, map->exit_image);
    mlx_destroy_image(map->mlx, map->player_image);
    mlx_destroy_image(map->mlx, map->collectible_image);
    mlx_destroy_image(map->mlx, map->track_image);
    mlx_destroy_image(map->mlx, map->door_player_image);
    mlx_destroy_window(map->mlx, map->mlx_win);
    mlx_destroy_display(map->mlx);
    free(map->mlx);
    free_arr(map->str);

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


int main(int c, char **v)
{
    t_map   map;
    t_map1  map1;
    char **m;
    // check_name(v);
    m = ft_maps1(v);
    char **m2 = ft_maps2(v);
    map.map = m2;
    map1.str = m;
    check_map(&map, m);
    position_p(&map1);
    validate_inpute(&map, map1.positionx_p, map1.positiony_p, map.collectibles);
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
