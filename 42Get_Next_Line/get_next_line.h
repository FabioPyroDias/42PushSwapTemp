/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 08:21:43 by fda-cruz          #+#    #+#             */
/*   Updated: 2025/11/16 13:50:30 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *line, char *buffer);
int		validate_buffer(char **line, char *buffer);
void	update_buffer(char *buffer, size_t start);
char	*get_next_line(int fd);

#endif