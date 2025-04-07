/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:37:11 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/07 00:43:59 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_mlx_function(t_map1 *map1)
{
    void *s;
    map1->mlx = mlx_init();
    if (!map1->mlx)
        ft_distroy(s);
    map1->mlx_win = mlx_new_window(map1->mlx, map1->height *64, map1->width * 64, "so_long");
    if (!map1->mlx_win)
        ft_distroy(s);
    full_map(map1);
    mlx_key_hook(map1->mlx_win, ft_handler, map1);
    mlx_hook(map1->mlx_win, 17, 0, ft_distroy, map1);
    mlx_loop(map1->mlx);
    ft_distroy(s);
}