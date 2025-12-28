/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 22:00:41 by fabio             #+#    #+#             */
/*   Updated: 2025/11/16 14:34:14 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		result;

	if (fd < 0 || fd > __FD_SETSIZE)
		return (NULL);
	line = NULL;
	if (validate_buffer(&line, buffer))
		return (line);
	while (1)
	{
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == -1)
			return (NULL);
		if (result == 0)
			return (update_buffer(buffer, 0), line);
		line = ft_strjoin(line, buffer);
		if (line[ft_strlen(line) - 1] == '\n')
			return (update_buffer(buffer, ft_strlen(buffer)), line);
		update_buffer(buffer, result);
	}
}

/* #include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd = open("t.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
} */