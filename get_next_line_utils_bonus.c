/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:01:16 by otzarwal          #+#    #+#             */
/*   Updated: 2024/11/16 21:45:42 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*buff;
	size_t	size;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	total_len;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = (char *)malloc(total_len * sizeof(char));
	if (!new_str)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		new_str[i] = s1[i];
	j = -1;
	while (s2[++j])
		new_str[i++] = s2[j];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

int	ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*buff;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	buff = malloc(len + 1);
	if (!buff)
		return (NULL);
	while (i < len)
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
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
