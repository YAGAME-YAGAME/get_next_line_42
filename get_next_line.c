/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:38:12 by otzarwal          #+#    #+#             */
/*   Updated: 2024/11/11 21:41:58 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"


char *get_line(int fd, char *hold)
{
	char *buff;
	char *line;
	int read_char;

	read_char = 1;
	while(read_char > 0)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
		{
			free (hold);
			hold = NULL;
			return (NULL);
		}
		read_char = read(fd, buff, BUFFER_SIZE);

		hold = (ft_strjoin(hold, buff));
		if (ft_strchr(hold, '\n'))
			return (hold);

	}
	return (NULL);
}


char *check_newline(char *line)
{
	char *wline;
	int i;
	int j;

	j  = 0;
	i = 0;
	while(line[i])
	{
		if (line[i] == '\n')
		{
			i++;
			while(j < i)
			{
				wline[j] = line[j];
				j++;
			}
			wline[j] = '\0';
			wline = ft_strdup(wline);
			// printf("%s\n",wline);

			return (wline);
		}
		i++;
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

	line = get_line(fd, hold);
	printf("%s\n" , line);

	//line = check_newline(line);

	// printf("%s\n" , line);

	return line;


}

int main()
{
	int fd;
	char *line;

	fd = open("test.txt" , O_RDONLY);


	line = get_next_line(fd);
	// printf("%s\n", line);


	// while (read(fd, buff, BUFFER_SIZE))
	// {
	// 	buff[BUFFER_SIZE] = '\0';
	// 	printf("%s\n", buff);
	// }

	close(fd);
}
