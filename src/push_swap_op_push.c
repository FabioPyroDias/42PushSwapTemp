/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-cruz <fda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:12:36 by fda-cruz          #+#    #+#             */
/*   Updated: 2025/12/15 15:33:11 by fda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dst)
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
}

void	pb(t_stack *b, t_stack *a)
{
	push(b, a);
}
