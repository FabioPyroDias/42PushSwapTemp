#include "../include/push_swap.h"

void	push_min_value_to_b(t_stack *a, t_stack *b, int index)
{
	int	rotation;

	rotation = 0;
	if (index < 3)
	{
		while (rotation < index)
		{
			ra(a);
			rotation++;
		}
		pb(b, a);
	}
	else
	{
		while (index != 0)
		{
			rra(a);
			index = (index + 1) % a->size;
		}
		pb(b, a);
	}
}

void	sort_length_5(t_stack *a, t_stack *b)
{
	int	index;

	index = get_min_value_index(a->array, a->size);
	push_min_value_to_b(a, b, index);
	index = get_min_value_index(a->array, a->size);
	push_min_value_to_b(a, b, index);
	if (b->array[1] > b->array[0])
		sb(b);
	sort_length_3(a);
	pa(a, b);
	pa(a, b);
}
