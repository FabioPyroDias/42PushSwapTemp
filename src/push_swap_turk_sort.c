#include "../include/push_swap.h"

int	get_number_of_rotations_a(t_stack *a, int value)
{
	unsigned int	rotations;
	unsigned int	index;

	index = 0;
	rotations = 0;
	while (index < a->size - 1)
	{
		if (a->array[index] < value && a->array[index + 1] > value)
			return (index + 1);
		index++;
	}
	if (a->array[a->size - 1] < value && a->array[0] > value)
		return (0);
	rotations = get_max_value_index(a->array, a->size);
	return (rotations + 1);
}

void	get_nbr_rot(t_stack *a, t_stack *b, unsigned int *ai, unsigned int *bi)
{
	unsigned int	cost_b;
	unsigned int	cost_a;
	unsigned int	cost_total;
	unsigned int	current_index;

	current_index = 0;
	cost_total = UINT_MAX;
	while (current_index < b->size)
	{
		if (current_index <= b->size / 2)
			cost_b = current_index;
		else
			cost_b = b->size - current_index;
		cost_a = get_number_of_rotations_a(a, b->array[current_index]);
		if (cost_a > a->size / 2)
			cost_a = a->size - cost_a;
		if (cost_total > cost_b + cost_a || (cost_total == cost_b + cost_a
				&& b->array[current_index] > b->array[*bi]))
		{
			*bi = current_index;
			*ai = get_number_of_rotations_a(a, b->array[current_index]);
			cost_total = cost_b + cost_a;
		}
		current_index++;
	}
}

void	r_stacks(t_stack *a, t_stack *b, unsigned int *r_a, unsigned int *r_b)
{
	if (*r_a < a->size / 2 && *r_b < b->size / 2)
	{
		while (*r_a > 0 && *r_b > 0)
		{
			rr(a, b);
			(*r_a)--;
			(*r_b)--;
		}
	}
	else if (*r_a >= a->size / 2 && *r_b >= b->size / 2)
	{
		while (*r_a < a->size && *r_b < b->size)
		{
			rrr(a, b);
			(*r_a)++;
			(*r_b)++;
		}
	}
}

void	rotate_stack(t_stack *stack, unsigned int rotations, char passed_stack)
{
	if (rotations <= stack->size / 2)
	{
		while (rotations-- != 0)
		{
			if (passed_stack == 'a')
				ra(stack);
			else
				rb(stack);
		}
	}
	else
	{
		while (rotations++ != stack->size)
		{
			if (passed_stack == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}

void	turk_sort(t_stack *a, t_stack *b)
{
	unsigned int	min_value_index;

	push_chunks_to_b(a, b);
	sort_length_3(a);
	push_back_from_b(a, b);
	min_value_index = get_min_value_index(a->array, a->size);
	if (min_value_index <= a->size / 2)
		while (min_value_index-- != 0)
			ra(a);
	else
		while (min_value_index++ != a->size)
			rra(a);
}
