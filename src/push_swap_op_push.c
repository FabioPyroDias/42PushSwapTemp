/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:12:36 by fda-cruz          #+#    #+#             */
/*   Updated: 2025/12/21 01:25:00 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack *dst, t_stack *src)
{
	unsigned int	index;

	if (src->size == 0)
		return ;
	index = dst->size;
	while (index > 0)
	{
		index--;
		dst->array[index + 1] = dst->array[index];
	}
	dst->array[index] = src->array[0];
	dst->size++;
	while (index < src->size - 1)
	{
		src->array[index] = src->array[index + 1];
		index++;
	}
	src->size--;
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *b, t_stack *a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
