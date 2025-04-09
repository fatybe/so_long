/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:51:04 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/09 01:40:27 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handler(int key_code, t_map1 *map)
{
	if (key_code == 100)
		to_right(map);
	if (key_code == 97)
		to_left(map);
	if (key_code == 119)
		to_up(map);
	if (key_code == 115)
		to_down(map);
	if (key_code == 65307)
		ft_free_all(map);
	print_image(map);
	return (0);
}

char	**full_arr_with_newline(char **v)
{
	int		fd;
	int		len;
	char	**arr;
	char	*line;

	len = 0;
	len = find_size1(v);
	arr = malloc((len + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	fd = open(v[1], O_RDONLY);
	line = get_next_line2(fd);
	len = 0;
	while (line)
	{
		arr[len] = line;
		len++;
		line = get_next_line2(fd);
	}
	arr[len] = 0;
	close(fd);
	return (arr);
}

void	check_newline(char **v)
{
	int		i;
	char	**arr;
	int		j;

	i = 0;
	arr = full_arr_with_newline(v);
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][0] == '\n')
			{
				free_arr(arr);
				write(2, "empty line in map!!\n", 20);
				exit(1);
			}
			j++;
		}
		i++;
	}
	free_arr(arr);
}

char	**ft_maps1(char **v)
{
	int		fd;
	int		len;
	char	**arr;
	char	*line;

	check_newline(v);
	len = find_size(v);
	arr = malloc((len + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	fd = open(v[1], O_RDONLY);
	line = get_next_line(fd);
	len = 0;
	while (line)
	{
		arr[len] = line;
		len++;
		line = get_next_line(fd);
	}
	arr[len] = 0;
	close(fd);
	return (arr);
}

char	**ft_maps2(char **s)
{
	int		fd;
	int		len;
	char	**arr;
	char	*line;

	len = find_size(s);
	arr = malloc((len + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	fd = open(s[1], O_RDONLY);
	line = get_next_line(fd);
	len = 0;
	while (line)
	{
		arr[len] = line;
		len++;
		line = get_next_line(fd);
	}
	arr[len] = 0;
	close(fd);
	return (arr);
}
