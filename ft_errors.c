/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 00:28:05 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/07 00:47:50 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill(t_map *m, int x, int y)
{
    if (x < 0 || y < 0 || m->map[x][y] == '1' || m->map[x][y] == 'V' || m->map[x][y] == 'E')
    {
        if (m->map[x][y] == 'E')
            m->position_e += 1;
        return ;
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
int validate_inpute(t_map *m, int x, int y)
{
    m->position_e = 0;
    
    flood_fill(m, x, y);
    if (m->position_e == 0 || m->collectibles > 0)
        return (1);
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
    free(m);
}
int ft_distroy(void *param)
{
    t_map1 *map = (t_map1 *)param;
    if (map->mlx)
        mlx_destroy_image(map->mlx, map->wall_image);
    if (map->exit_image)
        mlx_destroy_image(map->mlx, map->exit_image);
    if (map->player_image)
        mlx_destroy_image(map->mlx, map->player_image);
    if (map->collectible_image)
        mlx_destroy_image(map->mlx, map->collectible_image);
    if (map->track_image)
        mlx_destroy_image(map->mlx, map->track_image);
    if (map->mlx_win)
        mlx_destroy_window(map->mlx, map->mlx_win);
    if (map->mlx) {
        mlx_destroy_display(map->mlx);
        free(map->mlx);
    }
    if (map->str)
        free_arr(map->str);

    exit(0);
    return (0);
}
