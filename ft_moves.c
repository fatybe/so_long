/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 00:24:01 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/08 00:10:58 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print(t_map1 *m)
{
	m->moves++;
	printf("%d\n", m->moves);
}

void	to_right(t_map1 *m)
{
	void	*s;
	int		i;
	int		j;

	ft_print(m);
	i = m->positionx_p;
	j = m->positiony_p;
	if (m->str[i][j + 1] == 'C' || m->str[i][j + 1] == '0')
	{
		if (m->str[i][j + 1] == 'C')
			m->c--;
	}
		m->str[i][j] = '0';
		m->str[i][j + 1] = 'P';
		m->positiony_p++;
		
	if (m->str[i][j + 1] == 'E')
	{
		if (m->c == 0)
		{
			ft_free_all(m);
			exit(0);
		}
	}
}

void	to_left(t_map1 *m)
{
	void	*s;
	int		i;
	int		j;

	ft_print(m);
	i = m->positionx_p;
	j = m->positiony_p;
	if (m->str[i][j - 1] == 'C' || m->str[i][j - 1] == '0')
	{
		if (m->str[i][j - 1] == 'C')
			m->c--;
		m->str[i][j] = '0';
		m->str[i][j - 1] = 'P';
		m->positiony_p--;
		
	}
	if (m->str[i][j - 1] == 'E')
	{
		if (m->c == 0)
		{
			ft_free_all(m);
			exit(0);
		}
	}
}

void	to_up(t_map1 *m)
{
	void	*s;
	int		i;
	int		j;

	ft_print(m);
	i = m->positionx_p;
	j = m->positiony_p;
	if (m->str[i - 1][j] == 'C' || m->str[i - 1][j] == '0')
	{
		if (m->str[i - 1][j] == 'C')
			m->c--;
		m->str[i][j] = '0';
		m->str[i - 1][j] = 'P';
		m->positionx_p--;
		
	}
	if (m->str[i - 1][j] == 'E')
	{
		if (m->c == 0)
		{
			ft_free_all(m);
			exit(0);
		}
	}
}

void	to_down(t_map1 *m)
{
	void	*s;
	int		i;
	int		j;

	ft_print(m);
	i = m->positionx_p;
	j = m->positiony_p;
	if (m->str[i + 1][j] == 'C' || m->str[i + 1][j] == '0')
	{
		if (m->str[i + 1][j] == 'C')
			m->c--;
		m->str[i][j] = '0';
		m->str[i + 1][j] = 'P';
		m->positionx_p++;
		
	}
	if (m->str[i + 1][j] == 'E')
	{
		if (m->c == 0)
		{
			ft_free_all(m);
			exit(0);
		}
	}
}
