/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:23:20 by fabio             #+#    #+#             */
/*   Updated: 2025/11/16 15:32:35 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	length;

	length = 0;
	if (!str)
		return (length);
	while (str[length] && str[length] != '\n')
		length++;
	if (str[length] == '\n')
		return (length + 1);
	return (length);
}

char	*ft_strjoin(char *line, char *buffer)
{
	size_t	index_line;
	size_t	index_buffer;
	size_t	length;
	char	*new_line;

	length = ft_strlen(line);
	length += ft_strlen(buffer);
	new_line = malloc(sizeof(char) * (length + 1));
	if (!new_line)
		return (NULL);
	index_line = 0;
	while (line && line[index_line])
	{
		new_line[index_line] = line[index_line];
		index_line++;
	}
	index_buffer = 0;
	while (index_line + index_buffer < length)
	{
		new_line[index_line + index_buffer] = buffer[index_buffer];
		index_buffer++;
	}
	new_line[index_line + index_buffer] = '\0';
	free(line);
	return (new_line);
}

void	update_buffer(char *buffer, size_t start)
{
	size_t	index;

	index = 0;
	while (index + start < BUFFER_SIZE)
	{
		buffer[index] = buffer[start + index];
		index++;
	}
	while (index < BUFFER_SIZE)
	{
		buffer[index] = '\0';
		index++;
	}
}

int	validate_buffer(char **line, char *buffer)
{
	size_t	length;
	int		found_newline;

	if (buffer[0] == 0)
		return (0);
	length = ft_strlen(buffer);
	found_newline = 0;
	if (buffer[length - 1] == '\n')
		found_newline = 1;
	*line = ft_strjoin(*line, buffer);
	update_buffer(buffer, length);
	return (found_newline);
}
