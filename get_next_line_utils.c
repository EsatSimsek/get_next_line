/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: essimsek <essimsek@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:26:09 by essimsek          #+#    #+#             */
/*   Updated: 2026/02/09 20:25:31 by essimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				x;
	unsigned char		*dst1;
	const unsigned char	*src1;

	x = 0;
	dst1 = (unsigned char *)dst;
	src1 = (const unsigned char *)src;
	if (dst1 == NULL && src1 == NULL)
		return (NULL);
	while (n > x)
	{
		dst1[x] = src1[x];
		x++;
	}
	return (dst1);
}

char	*ft_strjoin(char *res, char const *buffer)
{
	char	*dst;
	size_t	res_len;
	size_t	buffer_len;

	if (!res)
	{
		res = (char *)malloc(1 * sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '\0';
	}
	if (!buffer)
		return (free(res), NULL);
	res_len = ft_strlen(res);
	buffer_len = ft_strlen(buffer);
	dst = (char *)malloc(sizeof(char) * (res_len + buffer_len + 1));
	if (!dst)
		return (free(res), NULL);
	ft_memcpy(dst, res, res_len);
	ft_memcpy(dst + res_len, buffer, buffer_len);
	dst[res_len + buffer_len] = '\0';
	free(res);
	return (dst);
}
