/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:51:04 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/08 02:22:17 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handler(int key_code, t_map1 *map)
{
	void	*s;

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
char **ft_maps1(char **v)
{
    int fd;
    int len = 0;
    char **arr;
    char *line;
    char *k;
    fd = open(v[1], O_RDONLY);
    k = get_next_line(fd);
    if (k)
    {
        printf("Empty map\n");
        exit(1);        
    }
    if (!k)
    {
        printf("Empty map\n");
        exit(1);        
    }
    while (k)
    {
        len++;
        free(k);
        k = get_next_line(fd);
    }
    close (fd);
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
    close (fd);
    return (arr);
}

char **ft_maps2(char **s)
{
    int fd;
    int len = 0;
    char **arr;
    char *line;
    char *k;
    fd = open(s[1], O_RDONLY);
    k = get_next_line(fd);
    while (k)
    {
        len++;
        free(k);
        k = get_next_line(fd);
    }
        
    close (fd);
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
    close (fd);
    return (arr);
}
