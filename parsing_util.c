/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 02:21:12 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/06 04:09:50 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


char **ft_maps1(char **v)
{
    int fd;
    int len = 0;
    char **arr;
    char *line;
    fd = open(v[1], O_RDONLY);
    while ((get_next_line(fd)))
        len++;
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
    fd = open(s[1], O_RDONLY);
    while ((get_next_line(fd)))
        len++;
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
        free(line);
        line = get_next_line(fd);
    }
    arr[len] = 0;
    close (fd);
    return (arr);
}
int is_rectangle(char **map)
{
    int len = ft_strlen(map[0]);
    int i = 1;
    while (map[i])
    {
        if (ft_strlen(map[i]) != len)
            return (1);
        i++;
    }
    return (0);
}

int check_characters(char **map)
{
    int i = 0;
    int j;
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
int check_wall(char **map)
{
    int len = 0;
    int i = 0;
    
    int lens = ft_strlen(map[0]);
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
