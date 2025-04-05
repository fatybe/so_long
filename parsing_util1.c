/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 01:01:17 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/05 01:02:47 by fbenjama         ###   ########.fr       */
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
