/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 02:21:12 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/08 19:40:29 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_size(char **v)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(v[1], O_RDONLY);
	line = get_next_line(fd);
	len = 0;
	if (!line)
	{
		write (2, "Empty map\n", 10);
		exit(1);
	}
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (len);
}

int	find_size1(char **v)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(v[1], O_RDONLY);
	line = get_next_line2(fd);
	len = 0;
	while (line)
	{
		len++;
		free(line);
		line = get_next_line2(fd);
	}
	close(fd);
	return (len);
}

int	is_rectangle(char **map)
{
	int	len;
	int	i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (1);
		i++;
	}
	return (0);
}

int	check_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_wall(char **map)
{
	int	len;
	int	i;
	int	lens;

	len = 0;
	i = 0;
	lens = ft_strlen(map[0]);
	while (map[len])
		len++;
	while (map[0][i] && map[len - 1][i])
	{
		if (map[0][i] != '1' || map[len - 1][i] != '1')
			return (1);
		i++;
	}
	i = 1;
	while (i < len - 1)
	{
		if (map[i][0] != '1' || map[i][lens - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
