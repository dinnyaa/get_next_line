/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaghdas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:28:47 by dbaghdas          #+#    #+#             */
/*   Updated: 2021/04/15 20:50:31 by dbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_new_line(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*buff;
	int			result;
	static char	*str;

	result = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!is_new_line(str) && result != 0)
	{
		if ((result = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[result] = '\0';
		str = ft_join(str, buff);
	}
	free(buff);
	*line = ft_new_str(str);
	str = move_ptr(str);
	result = (result == 0 ? 0 : 1);
	return (result);
}
