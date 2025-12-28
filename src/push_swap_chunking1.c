#include "../include/push_swap.h"

int	get_chunk_count(t_stack *stack)
{
	if (stack->size <= 100)
		return (1);
	return (8);
}

int	exists_in_chunk(t_stack *a, int min, int max)
{
	int	index;

	index = 0;
	while ((unsigned int) index < a->size)
	{
		if (a->array[index] >= min && a->array[index] < max)
			return (index);
		index++;
	}
	return (-1);
}

void	push_chunk(t_stack *a, t_stack *b, int min, int max)
{
	int	rotations;

	rotations = 0;
	while (a->size > 3)
	{
		rotations = exists_in_chunk(a, min, max);
		if (rotations == -1)
			return ;
		rot_chunk(a, &rotations);
		pb(b, a);
		if (b->array[0] > min && b->array[0] < (min + max) / 2)
			rb(b);
	}
}

void	push_chunks_to_b(t_stack *a, t_stack *b)
{
	int				chunk_count;
	int				chunk_size;
	int				current_chunk;
	unsigned int	chunk_max;

	chunk_count = get_chunk_count(a);
	chunk_size = a->size / chunk_count;
	current_chunk = 0;
	chunk_max = chunk_size;
	while (a->size > 3 && current_chunk < chunk_count)
	{
		push_chunk(a, b, current_chunk * chunk_size, chunk_max);
		chunk_max += chunk_size;
		current_chunk++;
		if (current_chunk == chunk_count - 1)
			chunk_max = INT_MAX;
	}
}

void	push_back_from_b(t_stack *a, t_stack *b)
{
	unsigned int	rot_a;
	unsigned int	rot_b;

	while (b->size > 0)
	{
		rot_a = 0;
		rot_b = 0;
		get_nbr_rot(a, b, &rot_a, &rot_b);
		r_stacks(a, b, &rot_a, &rot_b);
		rotate_stack(a, rot_a, 'a');
		rotate_stack(b, rot_b, 'b');
		pa(a, b);
	}
}
