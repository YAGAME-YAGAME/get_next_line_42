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

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

void get_line(int fd, t_list **list)
{
	char *buff;
	t_list *new;
	int rd;

	rd = 1;
	while(rd > 0)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return ;
		rd = read(fd , buff , BUFFER_SIZE);
		if (rd <= 0)
		{
			free(*list);
			*list = NULL;
			return ;
		}
		buff[rd] = '\0';
		new = ft_lstnew(buff);
		ft_lstadd_back(list, new);
		if (ft_strchr(new->content, '\n'))
			break;
	}

}

char *after(t_list *list)
{
	int i;

	i = 0;
	char *line;
	while(list)
	{

		if (ft_strchr(list->content, '\n'))
		{

		}
		i++;

	}
}

char *get_next_line(int fd)
{
	static t_list *hold;
	char *line;

	hold = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	get_line(fd, &hold);

	line = after(hold);
	// while (hold)
	// {
	// 	printf("%s\n", hold->content);
	// 	hold = hold->next;
	// }


	return (line);
}

int main()
{
	int fd;
	char *line;

	fd = open("test.txt" , O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);


	close(fd);
}
