/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:41:12 by otzarwal          #+#    #+#             */
/*   Updated: 2024/11/16 21:36:29 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

char	*resit(char *hold)
{
	int		i;
	char	*ret;

	i = 0;
	if (!hold)
		return (NULL);
	while (hold[i])
	{
		if (hold[i] == '\n')
		{
			ret = ft_substr(hold, i + 1, ft_strlen(hold) - i);
			free(hold);
			hold = NULL;
			return (ret);
		}
		i++;
	}
	return (NULL);
}

char	*befor_newline(char **hold)
{
	int		i;
	char	*line;
	char	*current;

	i = 0;
	current = *hold;
	if (hold && current)
	{
		while (current[i])
		{
			if (current[i] == '\n')
				return (ft_substr(current, 0, i + 1));
			i++;
		}
		if (current[i] == '\0')
		{
			line = ft_substr(current, 0, i);
			free(current);
			*hold = NULL;
			return (line);
		}
	}
	return (NULL);
}

static char	*get_line(int fd, char *hold)
{
	char	buff[BUFFER_SIZE + 1];
	int		rd;

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd < 0)
		{
			free(hold);
			hold = NULL;
			return (NULL);
		}
		buff[rd] = '\0';
		hold = ft_strjoin(hold, buff);
		if (!hold || ft_strchr(hold, '\n'))
			break ;
	}
	return (hold);
}

char	*get_next_line(int fd)
{
	static char	*hold[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	hold[fd] = get_line(fd, hold[fd]);
	if (!hold[fd])
		return (NULL);
	line = befor_newline(&hold[fd]);
	if (!line)
	{
		free(hold[fd]);
		hold[fd] = NULL;
		return (NULL);
	}
	hold[fd] = resit(hold[fd]);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		fd;
// 	int		i;

// 	i = 0;
// 	fd = open("test.txt", O_RDONLY);
// 	line = NULL;
// 	while (i < 50)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// }
