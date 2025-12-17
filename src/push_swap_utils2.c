/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-cruz <fda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:19:25 by fda-cruz          #+#    #+#             */
/*   Updated: 2025/12/17 14:56:50 by fda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ft_strdup(char *str, int start, int length)
{
	char	*dup;
	int		index;

	dup = malloc(sizeof(char) * (length + 1));
	if (!dup)
		return (NULL);
	index = 0;
	while (index < length)
	{
		dup[index] = str[start + index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}

int	count_words(char *str)
{
	int	index;
	int	found_nbr;
	int	count;

	index = 0;
	found_nbr = 0;
	count = 0;
	while (str[index])
	{
		if (str[index] >= '0' && str[index] <= '9')
			found_nbr = 1;
		else
		{
			if (found_nbr)
				count++;
			found_nbr = 0;
		}
		index++;
	}
	if (found_nbr)
		count++;
	return (count);
}

int	are_nbrs_in_range(long **array, int	size, char *nbrs[])
{
	int	index;

	index = 1;
	while (index < size)
	{
		
	}
}

int	are_nbrs_dup(long *array, int size, char *nbrs[])
{
	
}

int	are_valid_nbrs(int size, char *nbrs[])
{
	long	*arr;
	int		index;
	int		length;

	index = 1;
	length = 0;
	while (index < size)
	{
		length += count_words(nbrs[index]);
		index++;
	}
	printf("Length: %d\n", length);
	arr = malloc(sizeof(int) * length);
	if (!arr)
	{
		write(2, "Error: Failed to Allocate Memory\n", 33);
		return (0);
	}
	if (!are_nbrs_in_range(&arr, size, nbrs, length) || !are_nbrs_dup(arr, size, nbrs))
	{
		free(arr);
		return (0);
	}
	free(arr);
	return (1);
}
