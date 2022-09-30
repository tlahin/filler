/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:07:54 by tlahin            #+#    #+#             */
/*   Updated: 2022/01/17 13:07:58 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	adjuster(char **str, char **line)
{
	int		n;
	char	*temp;

	n = 0;
	while ((*str)[n] != '\0' && (*str)[n] != '\n')
		n++;
	if ((*str)[n] == '\n')
	{
		*line = ft_strsub(*str, 0, n);
		temp = ft_strdup(&(*str)[n + 1]);
		free(*str);
		*str = temp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

static int	check(char **str, char **line, int i, int fd)
{
	if (i < 0)
		return (-1);
	else if (i == 0 && str[fd] == NULL)
		return (0);
	else
		return (adjuster(&str[fd], line));
}

int	get_next_line(const int fd, char **line)
{
	int			i;
	char		buffer[BUFF_SIZE + 1];
	static char	*str[FD_SIZE];
	char		*temp;

	if (fd < 0 || line == NULL)
		return (-1);
	i = read(fd, buffer, BUFF_SIZE);
	while (i > 0)
	{
		buffer[i] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
		i = read(fd, buffer, BUFF_SIZE);
	}
	return (check(str, line, i, fd));
}
