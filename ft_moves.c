/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 00:24:01 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/09 01:40:05 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print(t_map1 *m)
{
	m->moves++;
	putnbr(m->moves);
	write (1, "\n", 1);
}

void	to_right(t_map1 *m)
{
	int		i;
	int		j;

	i = m->positionx_p;
	j = m->positiony_p;
	if (m->str[i][j + 1] == 'C' || m->str[i][j + 1] == '0')
	{
		if (m->str[i][j + 1] == 'C')
			m->c--;
		m->str[i][j] = '0';
		m->str[i][j + 1] = 'P';
		m->positiony_p++;
		ft_print(m);
	}
	if (m->str[i][j + 1] == 'E')
	{
		if (m->c == 0)
		{
			ft_print(m);
			ft_free_all(m);
			exit(0);
		}
	}
}

void	to_left(t_map1 *m)
{
	int		i;
	int		j;

	i = m->positionx_p;
	j = m->positiony_p;
	if (m->str[i][j - 1] == 'C' || m->str[i][j - 1] == '0')
	{
		if (m->str[i][j - 1] == 'C')
			m->c--;
		m->str[i][j] = '0';
		m->str[i][j - 1] = 'P';
		m->positiony_p--;
		ft_print(m);
	}
	if (m->str[i][j - 1] == 'E')
	{
		if (m->c == 0)
		{
			ft_print(m);
			ft_free_all(m);
			exit(0);
		}
	}
}

void	to_up(t_map1 *m)
{
	int		i;
	int		j;

	i = m->positionx_p;
	j = m->positiony_p;
	if (m->str[i - 1][j] == 'C' || m->str[i - 1][j] == '0')
	{
		if (m->str[i - 1][j] == 'C')
			m->c--;
		m->str[i][j] = '0';
		m->str[i - 1][j] = 'P';
		m->positionx_p--;
		ft_print(m);
	}
	if (m->str[i - 1][j] == 'E')
	{
		if (m->c == 0)
		{
			ft_print(m);
			ft_free_all(m);
			exit(0);
		}
	}
}

void	to_down(t_map1 *m)
{
	int		i;
	int		j;

	i = m->positionx_p;
	j = m->positiony_p;
	if (m->str[i + 1][j] == 'C' || m->str[i + 1][j] == '0')
	{
		if (m->str[i + 1][j] == 'C')
			m->c--;
		m->str[i][j] = '0';
		m->str[i + 1][j] = 'P';
		m->positionx_p++;
		ft_print(m);
	}
	if (m->str[i + 1][j] == 'E')
	{
		if (m->c == 0)
		{
			ft_print(m);
			ft_free_all(m);
			exit(0);
		}
	}
}
