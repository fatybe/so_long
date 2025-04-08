/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenjama <fbenjama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:01:41 by fbenjama          #+#    #+#             */
/*   Updated: 2025/04/08 18:12:31 by fbenjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

char	*readfd2(int fd, char *buffer1)
{
	ssize_t	n;
	char	*buffer;

	n = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(buffer1), NULL);
	while (ft_strchr(buffer1, '\n') == NULL && n != 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
			return (free(buffer1), free(buffer), (NULL));
		if (n == 0)
			break ;
		buffer[n] = '\0';
		buffer1 = ft_strjoin(buffer1, buffer);
		if (n < BUFFER_SIZE)
			break ;
	}
	free(buffer);
	return (buffer1);
}

char	*next_line2(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!buffer || ft_strchr(buffer, '\n') == NULL)
		return (ft_strdup(buffer));
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (NULL);
	while (j < i)
	{
		str[j] = buffer[j];
		j++;
	}
	str[j++] = '\n';
	str[j++] = '\0';
	return (str);
}

char	*update2(char *s)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	if (!s || ft_strchr(s, '\n') == NULL)
	{
		if (s)
			free(s);
		return (NULL);
	}
	while (s[i] != '\n')
		i++;
	i++;
	new_str = malloc((ft_strlen(s) - i) + 1);
	if (!new_str)
		return (NULL);
	while (s[i])
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	free(s);
	return (new_str);
}

char	*get_next_line2(int fd)
{
	static char	*s;
	char		*str;

	if (fd < 0)
		return (NULL);
	s = readfd2(fd, s);
	if (!s)
		return (NULL);
	str = next_line2(s);
	if (str[0] == 0)
	{
		free(str);
		free(s);
		s = NULL;
		return (NULL);
	}
	s = update2(s);
	return (str);
}