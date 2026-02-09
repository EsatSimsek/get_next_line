/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: essimsek <essimsek@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:24:22 by essimsek          #+#    #+#             */
/*   Updated: 2026/02/09 20:26:12 by essimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_static(int fd, char *static_res)
{
	char	*str;
	int		x;

	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	x = 1;
	while (!ft_strchr(static_res, '\n') && x != 0)
	{
		x = read(fd, str, BUFFER_SIZE);
		if (x == -1)
		{
			free(str);
			free(static_res);
			return (NULL);
		}
		str[x] = '\0';
		static_res = ft_strjoin(static_res, str);
	}
	free(str);
	return (static_res);
}

static char	*get_line(char *static_res)
{
	size_t	x;
	char	*line;

	if (!static_res || !*static_res)
		return (NULL);
	x = 0;
	while (static_res[x] != '\n' && static_res[x] != '\0')
	{
		x++;
	}
	if (static_res[x] == '\n')
		x++;
	line = (char *)malloc(sizeof(char) * (x + 1));
	if (!line)
		return (NULL);
	line[x] = '\0';
	ft_memcpy(line, static_res, x);
	return (line);
}

static char	*new_static_res(char *static_res)
{
	char	*new_res;
	size_t	x;
	size_t	r;

	x = 0;
	while (static_res[x] != '\n' && static_res[x] != '\0')
	{
		x++;
	}
	r = ft_strlen(static_res) - x - 1;
	if (static_res[x] == '\0' || r == 0)
	{
		free(static_res);
		return (NULL);
	}
	new_res = (char *)malloc(sizeof(char) * (r + 1));
	if (!new_res)
		return (NULL);
	ft_memcpy(new_res, static_res + x + 1, r);
	new_res[r] = '\0';
	free(static_res);
	return (new_res);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = read_to_static(fd, res);
	if (!res)
		return (NULL);
	line = get_line(res);
	res = new_static_res(res);
	return (line);
}
