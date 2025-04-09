/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 00:28:05 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/09 01:13:42 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *m, int x, int y)
{
	if (x < 0 || y < 0 || m->map[x][y] == '1' || m->map[x][y] == 'V'
		|| m->map[x][y] == 'E')
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

int	validate_inpute(t_map *m, int x, int y)
{
	m->position_e = 0;
	flood_fill(m, x, y);
	if (m->position_e == 1 && m->collectibles > 0)
	{
		write(2, "collectibles not found!!\n", 25);
		return (1);
	}
	if (m->position_e == 0)
	{
		write(2, "exit not found!!\n", 17);
		return (1);
	}
	return (0);
}

void	free_arr(char **m)
{
	int	i;

	i = 0;
	while (m[i])
	{
		free(m[i]);
		i++;
	}
	free(m);
}

void	ft_free_all(t_map1 *map)
{
	if (map->w_i)
		mlx_destroy_image(map->mlx, map->w_i);
	if (map->e_i)
		mlx_destroy_image(map->mlx, map->e_i);
	if (map->p_i)
		mlx_destroy_image(map->mlx, map->p_i);
	if (map->c_i)
		mlx_destroy_image(map->mlx, map->c_i);
	if (map->t_i)
		mlx_destroy_image(map->mlx, map->t_i);
	if (map->mlx_win)
		mlx_destroy_window(map->mlx, map->mlx_win);
	if (map->mlx)
	{
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	if (map->str)
		free_arr(map->str);
	exit(0);
}

int	ft_distroy(void *param)
{
	t_map1	*map;

	map = (t_map1 *)param;
	if (map->mlx)
		mlx_destroy_image(map->mlx, map->w_i);
	if (map->e_i)
		mlx_destroy_image(map->mlx, map->e_i);
	if (map->p_i)
		mlx_destroy_image(map->mlx, map->p_i);
	if (map->c_i)
		mlx_destroy_image(map->mlx, map->c_i);
	if (map->t_i)
		mlx_destroy_image(map->mlx, map->t_i);
	if (map->mlx_win)
		mlx_destroy_window(map->mlx, map->mlx_win);
	if (map->mlx)
	{
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	if (map->str)
		free_arr(map->str);
	exit(0);
	return (0);
}
