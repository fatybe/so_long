/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 00:23:09 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/09 01:11:17 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	full_map(t_map1 *m)
{
	load_image(m);
	print_image(m);
}

void	load_image(t_map1 *m)
{
	int	width;
	int	height;

	m->p_i = mlx_xpm_file_to_image(m->mlx, "images/player.xpm", &width,
			&height);
	if (!m->p_i)
		ft_free_all(m);
	m->t_i = mlx_xpm_file_to_image(m->mlx, "images/track.xpm", &width, &height);
	if (!m->t_i)
		ft_free_all(m);
	m->w_i = mlx_xpm_file_to_image(m->mlx, "images/water.xpm", &width, &height);
	if (!m->w_i)
		ft_free_all(m);
	m->e_i = mlx_xpm_file_to_image(m->mlx, "images/door.xpm", &width, &height);
	if (!m->e_i)
		ft_free_all(m);
	m->c_i = mlx_xpm_file_to_image(m->mlx, "images/collectible.xpm", &width,
			&height);
	if (!m->c_i)
		ft_free_all(m);
}

void	ft_print_image(t_map1 *m, int i, int j)
{
	if (m->str[i][j] == 'P')
		mlx_put_image_to_window(m->mlx, m->mlx_win, m->p_i, j * 64, i * 64);
	if (m->str[i][j] == '0')
		mlx_put_image_to_window(m->mlx, m->mlx_win, m->t_i, j * 64, i * 64);
	if (m->str[i][j] == '1')
		mlx_put_image_to_window(m->mlx, m->mlx_win, m->w_i, j * 64, i * 64);
	if (m->str[i][j] == 'E')
		mlx_put_image_to_window(m->mlx, m->mlx_win, m->e_i, j * 64, i * 64);
	if (m->str[i][j] == 'C')
		mlx_put_image_to_window(m->mlx, m->mlx_win, m->c_i, j * 64, i * 64);
}

void	print_image(t_map1 *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->str[i])
	{
		j = 0;
		while (m->str[i][j])
		{
			ft_print_image(m, i, j);
			j++;
		}
		i++;
	}
}
