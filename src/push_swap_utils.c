/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-cruz <fda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:46:01 by fda-cruz          #+#    #+#             */
/*   Updated: 2025/12/18 11:10:36 by fda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack(int *array, int length)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	if (!array)
	{
		stack->array = array;
		stack->size = length;
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
	free(a);
	free(b);
	free(array);
}