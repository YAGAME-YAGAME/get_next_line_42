/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:01:16 by otzarwal          #+#    #+#             */
/*   Updated: 2024/11/14 18:24:20 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*buff;
	size_t	size;
	int i;

	i = 0;
	size = ft_strlen(s1);
	buff = malloc(size + 1);
	if (!buff)
		return (NULL);
	while (s1[i])
	{
		buff[i] = s1[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}



char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;
	int		size;
	int i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));

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
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*buff;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		len = 0;
		start = 0;
	}
	else if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	buff = malloc(len + 1);
	if (!buff)
		return (NULL);
	while (s[start + i] && i < len)
	{
		buff[i] = s[start + i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
