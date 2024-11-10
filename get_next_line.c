/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:38:12 by otzarwal          #+#    #+#             */
/*   Updated: 2024/11/10 22:44:27 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"


void	add_back(t_list *list, char *s)
{
	t_list *new, *last;

	last = list;
	if(last == NULL)
		last = new;
	else
	{
		while(last->next != NULL)
			last = last->next;
		last = new;
	}
	new->content = s;
	new->next = NULL;

}



t_list *get_line(int fd, t_list **list)
{
	int read_char;

	char *buff;
	int n =1;
	while(n)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return NULL;

		read_char = read(fd, buff , BUFFER_SIZE);
		if (read_char <= 0)
		{
			free(buff);
			n = 0;
			return NULL;
		}
		buff[read_char] = '\0';

		add_back(*list, buff);
	}
	return (*list);
}


char *get_next_line(int fd)
{
	static t_list *list;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	list = get_line(fd, &list);

	return ("otmane");
}

int main()
{
	int fd;
	char *line;

	fd = open("test.txt" , O_RDONLY);


	line = get_next_line(fd);
	printf("%s\n", line);
	// while (read(fd, buff, BUFFER_SIZE))
	// {
	// 	buff[BUFFER_SIZE] = '\0';
	// 	printf("%s\n", buff);
	// }

	close(fd);
}
