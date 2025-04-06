/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:27:02 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/06 04:15:06 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int c, char **v)
{
    (void) c;
    t_map   map;
    t_map1  map1;
    char **m;
    // check_name(v);
    m = ft_maps1(v);
    char **m2 = ft_maps2(v);
    ft_initialize(&map1);
    map.map = m2;
    map1.str = m;
    check_map(&map, m);
    position_p(&map1);
    validate_inpute(&map, map1.positionx_p, map1.positiony_p);
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
