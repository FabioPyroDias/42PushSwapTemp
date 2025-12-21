/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:46:01 by fda-cruz          #+#    #+#             */
/*   Updated: 2025/12/21 20:15:43 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack(int *array, int length)
{
	t_stack	*stack;
	int		*empty_array;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	if (array)
	{
		stack->array = array;
		stack->size = length;
	}
	else
	{
		empty_array = malloc(sizeof(int) * length);
		if (!empty_array)
			return (NULL);
		stack->array = empty_array;
		stack->size = 0;
	}
	stack->capacity = length;
	return (stack);
}

int	is_sorted(int *array, int length)
{
	int	index;

	index = 1;
	while (index < length)
	{
		if (array[index - 1] > array[index])
				return (0);
		index++;
	}
	return (1);
}

void	free_all(t_stack *a, t_stack *b, int *array)
{
	if (array)
		free(array);
	if (a)
		free(a);
	if (b)
	{
		if (b->array)
			free(b->array);
		free(b);
	}
}

int	get_min_value_index(int	*array, int length)
{
	int	min_value_index;
	int	index;

	index = 0;
	min_value_index = index;
	while (index < length)
	{
		if (array[min_value_index] > array[index])
			min_value_index = index;
		index++;
	}
	return (min_value_index);
}
