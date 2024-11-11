/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:01:16 by otzarwal          #+#    #+#             */
/*   Updated: 2024/11/11 17:55:20 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*buff;
	size_t	size;

	size = ft_strlen(s1);
	buff = malloc(size + 1);
	if (!buff)
		return (NULL);
	ft_strlcpy(buff, s1, size + 1);
	return (buff);
}



char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;
	int		size;
	int i;

	i = 0;
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	buff = malloc(size);
	if (!buff)
		return (NULL);
	while(*s1)
	{
		buff[i++] = *s1;
		s1++;
	}
	while(*s2)
	{
		buff[i++] = *s2;
		s2++;
	}
	buff[i] = '\0';

	// ft_strlcpy(buff, s1, ft_strlen(s1) + 1);
	// ft_strlcat(buff, s2, size);
	return (buff);
}


int ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}
// size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	size_t	dlen;
// 	size_t	slen;
// 	size_t	i;

// 	slen = ft_strlen(src);
// 	if (size == 0 && !dst)
// 		return (slen);
// 	dlen = ft_strlen(dst);
// 	i = 0;
// 	if (size <= dlen)
// 		return (size + slen);
// 	while (i < size - dlen - 1 && src[i])
// 	{
// 		dst[dlen + i] = src[i];
// 		i++;
// 	}
// 	dst[dlen + i] = '\0';
// 	return (dlen + slen);
// }

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
