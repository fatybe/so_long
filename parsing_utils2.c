/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 00:49:39 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/06 00:51:17 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_initialize(t_map1 *m)
{
    m->positionx_p = 0;
    m->positiony_p = 0;
    m->mlx = NULL;
    m->mlx_win = NULL;
    m->track_image = NULL;
    m->collectible_image = NULL;
    m->door_player_image = NULL;
    m->exit_image = NULL;
    m->player_image = NULL;
    m->height = 0;
    m->width = 0;
    m->moves = 0;
    m->c = 0;
    m->wall_image = NULL;
}
void ft_error(void)
{
    write(2, "invalide name\n", 15);
        exit(1);
}
void check_name(char **v)
{
    int len;
    len = ft_strlen(v[1]);
    if (v[1][len - 1] != 'r')
        ft_error(); 
    else if (v[1][len - 2] != 'e')
    ft_error(); 
    else if (v[1][len - 3] != 'b')
        ft_error(); 
    else if (v[1][len - 4] != '.')
        ft_error();  
    else if (v[1][len - 5] == '/')
        ft_error();
}