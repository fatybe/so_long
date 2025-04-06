/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 00:23:09 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/06 04:03:00 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void full_map(t_map1 *m)
{
    load_image(m);
    print_image(m);
}
void load_image(t_map1 *m)
{
    int width;
    int height;
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
