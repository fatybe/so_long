/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:27:02 by fbenjama          #+#    #+#             */
/*   Updated: 2025/03/30 23:55:26 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_util(char c, t_a *a)
{
    if (c == 'P')
        a->p++;
    if (c == 'E')
        a->e++;
    if (c == 'C')
        a->c++;
}
int ft_check(char **m)
{
    t_a a;
    int i;
    int j;
    
    i = 0;
    a.p = 0;
    a.e = 0;
    a.c = 0;
    while (m[i])
    {
        j = 0;
        while (m[i][j])
        {
            ft_util(m[i][j], &a);
            j++;
        }
        i++;
    }
    if (a.p != 1 || a.e != 1 || a.c < 1)
        return (1);
    return (0);
}
void    check_map(char **m)
{
    if (is_rectangle(m) == 1)
        write(2, "invalide map\n", 14);
    if (check_characters(m) == 1)
        write(2, "invalide map\n", 14);
    if (check_wall(m) == 1)
        write(2, "invalide map\n", 14);
    if (ft_check(m) == 1)
        write(2, "invalide map\n", 14);
}
void position_p(char **m, t_map *map)
{
    int i;
    int j;
     
    map->positionx_p = 0;
    map->positiony_p = 0;
    map->collectibles = 0;
    i = 0;
    while (m[i])
    {
        j = 0;
        while (m[i][j])
        {
            
            if (m[i][j] == 'P')
            {
                map->positionx_p = j;
                map->positiony_p = i;
            }
            if (m[i][j] == 'C')
                map->collectibles++;
            j++;
        }
        i++;
    }
}

void flood_fill(char **m, int x, int y, int total_collectible)
{
    int position_e = 0;
    int collectible = 0;
    if (x > 0 || y > 0 || m[x][y] == '1' || m[x][y] == 'V')
        return ;
    if (m[x][y] == 'E')
        position_e = 1;
    if (m[x][y] == '0' || m[x][y] == 'C' || m[x][y] == 'P')
    {
        m[x][y] == 'V';
        if (m[x][y] == 'C')
            collectible++;
    }
    flood_fill(m, x + 1, y, total_collectible);
    flood_fill(m, x - 1, y, total_collectible);
    flood_fill(m, x, y + 1, total_collectible);
    flood_fill(m ,x, y - 1, total_collectible);
}
validate_inpute(char **m, int x, int y, int total_collectible)
{
    
}
int main(int c, char **v)
{
    t_map   map;
    int fd;
    char **m;
    check_name(v);
    m = ft_maps(v);
    map.map = m;
    check_map(m);
    position_p(m, &map);
    validate_map(m, map.positionx_p, map.positiony_p, map.collectibles)
}
