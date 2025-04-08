/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 01:01:17 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/08 18:57:00 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_util(char c, t_map *a)
{
	if (c == 'P')
		a->p++;
	if (c == 'E')
		a->e++;
	if (c == 'C')
		a->collectibles++;
}

int	ft_check(t_map *a)
{
	int	i;
	int	j;

	i = 0;
	a->p = 0;
	a->e = 0;
	a->collectibles = 0;
	while (a->map[i])
	{
		j = 0;
		while (a->map[i][j])
		{
			ft_util(a->map[i][j], a);
			j++;
		}
		i++;
	}
	if (a->p != 1 || a->e != 1 || a->collectibles < 1)
		return (1);
	return (0);
}

void	parsing_error(t_map *map, t_map1 *m)
{
	write(2, "invalide map\n", 14);
	free_arr(map->map);
	free_arr(m->str);
	exit(0);
}

void	check_map(t_map *map, t_map1 *m)
{
	if (is_rectangle(map->map) == 1)
	{
		printf("hi0\n");
		parsing_error(map, m);
	}
	if (check_characters(map->map) == 1)
	{
		printf("hi2\n");
		parsing_error(map, m);
	}
	if (check_wall(map->map) == 1)
	{
		printf("hi1\n");
		parsing_error(map, m);
	}
	if (ft_check(map) == 1)
	{
		parsing_error(map, m);
	}
}

void	position_p(t_map1 *map)
{
	int	i;
	int	j;

	i = 0;
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
