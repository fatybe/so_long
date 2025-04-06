/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 00:24:01 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/06 03:59:37 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void ft_print(t_map1 *m)
{
    m->moves++;
    printf("%d\n", m->moves);
}
void to_right(t_map1 *m)
{
    ft_print(m);
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
    }
}
void to_left(t_map1 *m)
{
    ft_print(m);
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
    }
}
void to_up(t_map1 *m)
{
    ft_print(m);
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
    }
}
void to_down(t_map1 *m)
{
    ft_print(m);
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
    }
}
int ft_handler (int key_code, t_map1 *map)
{
    // map->moves = 0;
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

