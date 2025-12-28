#include "../include/push_swap.h"

void	rot_chunk(t_stack *a, int *rotations)
{
	if ((unsigned int) *rotations < a->size / 2)
	{
		while (*rotations != 0)
		{
			ra(a);
			(*rotations)--;
		}
	}
	else
	{
		while ((unsigned int) *rotations < a->size)
		{
			rra(a);
			(*rotations)++;
		}
	}
}
