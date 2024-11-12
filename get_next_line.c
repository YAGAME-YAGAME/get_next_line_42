// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:38:12 by otzarwal          #+#    #+#             */
/*   Updated: 2024/11/12 10:41:12 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        size_t  i;
        char    *buff;

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
        ft_strlcpy(buff, s + start, len + 1);
        return (buff);
}

char *check_newline(char *hold)
{
	int i;
	char *befor_newline;

	i = 0;
	if (!*hold)
		return (NULL);
	while (hold[i])
	{
		if (hold[i] == '\n')
		{
			i++;
			befor_newline = ft_substr(hold, 0, i);
			return (befor_newline);
		}
		i++;
	}
	return (hold);
}

char *get_line(int fd, char *hold)
{
	char buff[BUFFER_SIZE + 1];
	int read_char;

	read_char = 1;
	while (read_char > 0)
	{
		read_char = read(fd, buff, BUFFER_SIZE);
		if (read_char < 0 )
		{
			free(hold);
			hold = NULL;
			return NULL;
		}
		buff[read_char] = '\0';
		hold = ft_strjoin(hold, buff);
		if (ft_strchr(hold, '\n'))
			break;
	}
	return (hold);
}

char	*process_line(char **stash)
{
	int		i;
	char	*line;
	char	*current_stash;

	i = 0;
	current_stash = *stash;
	if (stash && current_stash)
	{
		while (current_stash[i])
		{
			if (current_stash[i] == '\n')
				return (ft_substr(current_stash, 0, i + 1));
			i++;
		}
		if (current_stash[i] == '\0')
		{
			line = ft_substr(current_stash, 0, i);
			free(current_stash);
			*stash = NULL;
			return (line);
		}
	}
	return (NULL);
}


char *get_next_line(int fd)
{
	static char *hold;
	char *line;

	hold = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	hold = get_line(fd, hold);
	if (!hold)
		return (NULL);

	line = check_newline(hold);
	if (!line)
	{
		free(hold);
		hold = NULL;
		return NULL;
	}

	hold = process_line(&hold);
	return line;
}

int main()
{
	int fd;
	char *line;

	fd = open("test.txt" , O_RDONLY);


	// line = get_next_line(fd);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));


	// while (read(fd, buff, BUFFER_SIZE))
	// {
	// 	buff[BUFFER_SIZE] = '\0';
	// 	printf("%s\n", buff);
	// }

	close(fd);
}
