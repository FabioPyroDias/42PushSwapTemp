#include "../include/push_swap.h"

int	get_number_of_rotations_a(t_stack *a, int value)
{
	int	target;
	int	rotations;
	int	index;

	index = 0;
	rotations = get_min_value_index(a->array, a->size);
	target = a->array[rotations];
	while (index < a->size)
	{
		if (a->array[index] > value && a->array[index] < target)
		{
			rotations = index;
			target = a->array[index];
		}
		index++;
	}
	return (rotations);
}

void	get_number_of_rotations(t_stack *a, t_stack *b, int *a_i, int *b_i)
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
		if (cost_total > cost_b + cost_a)
		{
			*b_i = current_index;
			*a_i = get_number_of_rotations_a(a, b->array[current_index]);
			cost_total = cost_b + cost_a;
		}
		current_index++;
	}
}

void	rotate_both_stacks(t_stack *a, t_stack *b, int *rot_a, int *rot_b)
{
	if (*rot_a <= a->size / 2 && *rot_b <= b->size / 2)
	{
		while (*rot_a > 0 && *rot_b > 0)
		{
			rr(a, b);
			*rot_a--;
			*rot_b--;
		}
	}
	else if(*rot_a > a->size / 2 && *rot_b > b->size / 2)
	{
		while (*rot_a < a->size && *rot_b < b->size)
		{
			rrr(a, b);
			*rot_a++;
			*rot_b++;
		}
	}
}

void	rotate_stack(t_stack *stack, int rotations, char passed_stack)
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
			if (passed_stack == 'a')
				rra(stack);
			else
				rrb(stack);
	}
}

void	turk_sort(t_stack *a, t_stack *b)
{
	int	index;
	int	rotation_a;
	int	rotation_b;
	int	min_value_index;

	while (a->size > 3)
		pb(b, a);
	sort_length_3(a);
	while (b->size != 0)
	{
		get_number_of_rotations(a, b, &rotation_a, &rotation_b);
		rotate_both_stacks(a, b, &rotation_a, &rotation_b);
		rotate_stack(a, rotation_a, 'a');
		rotate_stack(b, rotation_b, 'b');
		pa(a, b);
	}
	min_value_index = get_min_value_index(a->array, a->size);
	if (min_value_index <= a->size / 2)
		while (min_value_index-- != 0)
			ra(a);
	else
		while (min_value_index++ != a->size)
			rra(a);
}
