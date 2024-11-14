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

char *after_newline(char *line)
{
	int i;
	char *res;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			i++;
			res = ft_substr(line, 0, i);
			break;
		}
		i++;
	}
	return (res);
}

void get_line(int fd, char **hold)
{
	char *buff;
	int rd;
	char *res;

	rd  = 1;
	while(rd > 0)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return ;
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd <= 0)
		{
			free(hold);
			hold = NULL;
			return ;
		}
		*hold = ft_strjoin(*hold, buff);
		if (ft_strchr(*hold, '\n'))
			break;
	}
}

char *get_next_line(int fd)
{
	static char *hold;
	char *line;

	get_line(fd, &hold);

	line = after_newline(hold);
	printf("%s", line);


	hold = NULL;
	return (line);
}



int main()
{
	int fd;
	char *line;

	fd = open("test.txt" , O_RDONLY);

	get_next_line(fd);
	get_next_line(fd);



	close(fd);
}
