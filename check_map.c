/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:48:32 by fbenjama          #+#    #+#             */
/*   Updated: 2025/03/29 03:27:38 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_strlen (char *s)
{
    int i;
    i = 0;
    while (s[i])
        i++;
    return (i);
}
int is_rectangle(char **str)
{
    int a;
    int i = 1;
    int j;
    a = ft_strlen(str[0]);
    while (str[i] != NULL)
    {
        j = ft_strlen(str[i]);
        if (j != a)
            return (1);
        i++;
    }
    return (0);
}
int check_character(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != 'P'
            && str[i] != 'E' && str[i] != 'C')
                return (1);
        i++;
    }
    return (0);
}

// int wall_is_1(char *str)
// {
//     int len;
//     int i = 0;
//     int k = 0;
//     len = ft_strlen(str);
//     while (str[i])
//     {
//         while (str[i] && str[i] != 32)
//         {
//             if (str[i] != '1')
//                 return (1);
//             i++;
//         }
//         if (str[i] == 32)
//             i++;
//     }
// }
// void    ft_check(char **str)
// {
//     if (is_rectangle(*str) == 1)
//         // invalide
//     if (check_character(*str) == 1)
//         // invalide
//     if (wall_is_1(*str) == 1)
//         // invalide
    
// }
int main()
{
    char *str[] = {"111111111","111111111","111111111"};
    if (is_rectangle(str) == 1)
        printf("INVALIDE\n");
    else   
        printf("VALIDE\n");
    return (0);
}