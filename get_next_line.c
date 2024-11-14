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

char *befor_newline(char *line)
{
	int i;
	char *res;

	i = 0;
	res = NULL;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	res = ft_substr(line, 0, ++i);
	return (res);
}

void	get_line(int fd, char **hold)
{
	char *buff;
	char *tmp;
	int rd;
	char *res;

	rd  = 1;
	tmp = NULL;
	// check is staick variable is fill or not
	if (*hold)
		return ;
	// initilize NULL it mean is empty
	*hold = NULL;
	// use calloc to initilize garbj value null termintor
	buff = calloc(BUFFER_SIZE + 1, 1);
	if (!buff)
		return ;
	while(rd > 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd <= 0) // check is read "read nothing or failed"
		{
			free(*hold);
			free(buff);
			buff = NULL;
			*hold = NULL;
			return ;
		}
		buff[BUFFER_SIZE] = '\0';
		*hold = ft_strjoin(*hold, buff);
		if (ft_strchr(*hold, '\n'))
			break;
	}
	return ;
}
char *resit(char *hold)
{
	char *res;
	int i;

	i = 0;
	if (!hold)
		return NULL;
	while(hold[i] && hold[i] != '\n')
		i++;
	i++;
	res = ft_substr(hold, i , (ft_strlen(hold) - i));
	return (res);
}


char *get_next_line(int fd)
{
	static char *hold;
	char *line;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	get_line(fd, &hold);
	if(!hold)
		return NULL;
	line = befor_newline(hold);
	hold = resit(hold);
	// check is emty string
	if (line && !*line)
		return NULL;
	return (line);
}



// int main()
// {
// 	int fd;
// 	char *line;

// 	fd = open("test.txt" , O_RDONLY);

// 	for (int i =1 ; i <= 20; i++)
// 	{
// 		line = get_next_line(fd);
// 		printf("%d::%s",i, line);
// 		free(line);
// 		line = NULL;
// 	}
// 	close(fd);
// }
