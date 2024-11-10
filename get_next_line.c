/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:38:12 by otzarwal          #+#    #+#             */
/*   Updated: 2024/11/10 23:22:20 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"


void	add_back(t_list **list, char *s)
{
	t_list *new, *last;

	new = malloc(sizeof(t_list));


	last = *list;
	if(last == NULL)
		*list = new;
	else
	{
		while(last->next != NULL)
			last = last->next;
		last->next = new;
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
		// printf("done");
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
		add_back(list, buff);
		printf("%p\n", *list);
		printf("%p\n", list);
	}
	return (*list);
}


char *get_next_line(int fd)
{
	static t_list *list;
	t_list *test;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	list = get_line(fd, &list);

	// printf("%s\n",list->content);

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
