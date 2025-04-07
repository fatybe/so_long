/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:27:02 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/07 00:37:09 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int c, char **v)
{
    (void) c;
    t_map   map;
    t_map1  map1;
    char **m;
    char **m2;

    check_name(v);
    m = ft_maps1(v);
    m2 = ft_maps2(v);
    ft_initialize(&map1);
    map.map = m2;
    map1.str = m;
    check_map(&map, &map1);
    position_p(&map1);
    if (validate_inpute(&map, map1.positionx_p, map1.positiony_p) == 1)
        parsing_error(&map, &map1);
    free_arr(map.map);
    ft_mlx_function(&map1);
}
