/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:37:15 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/08 16:47:54 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*read_into_buff(int fd, char *buff)
{
	char	*temp;
	int		b_read;

	b_read = 1;
	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (!ft_strchr2(buff, '\n') && b_read != 0)
	{
		b_read = read(fd, temp, BUFFER_SIZE);
		temp[b_read] = '\0';
		buff = ft_strjoin2(buff, temp);
	}
	free(temp);
	return (buff);
}

static char	*separate_line(char *buff)
{
	char	*ret_line;
	int		i;

	i = 0;
	if (!*buff)
		return (NULL);
	while (buff[i] != '\n' && buff[i])
		i++;
	ret_line = (char *)ft_calloc2(i + 2, 1);
	if (!ret_line)
		return (NULL);
	i = 0;
	while (buff[i] != '\n' && buff[i])
	{
		ret_line[i] = buff[i];
		i++;
	}
	ret_line[i] = buff[i];
	return (ret_line);
}

static char	*separate_rest(char *buff)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	temp = (char *)ft_calloc2(ft_strlen2(&buff[i]), 1);
	if (!temp)
		return (NULL);
	i++;
	while (buff[i + j])
	{
		temp[j] = buff[i + j];
		j++;
	}
	free(buff);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (read(fd, NULL, 0) == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = read_into_buff(fd, buff);
	if (!buff)
		return (NULL);
	line = separate_line(buff);
	buff = separate_rest(buff);
	return (line);
}