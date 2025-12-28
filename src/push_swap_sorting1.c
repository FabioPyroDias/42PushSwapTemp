#include "../include/push_swap.h"

void	sort_length_3(t_stack *a)
{
	int	*temp;

	temp = a->array;
	while (!is_sorted(temp, a->size))
	{
		if (temp[0] < temp[1] && temp[1] > temp[2])
			rra(a);
		if (temp[0] > temp[1] && temp[0] > temp[2])
			ra(a);
		if (temp[0] > temp[1] && temp[1] < temp[2])
			sa(a);
	}
}

void	sort_length_4_base(t_stack *a, t_stack *b)
{
	if (is_sorted(a->array, a->size))
		return ;
	pb(b, a);
	sort_length_3(a);
	pa(a, b);
}

void	sort_length_4(t_stack *a, t_stack *b)
{
	if (get_min_value_index(a->array, a->size) == 0)
		sort_length_4_base(a, b);
	else if (get_min_value_index(a->array, a->size) == 1)
	{
		ra(a);
		sort_length_4_base(a, b);
	}
	else if (get_min_value_index(a->array, a->size) == 2)
	{
		ra(a);
		ra(a);
		sort_length_4_base(a, b);
	}
	else
	{
		rra(a);
		sort_length_4_base(a, b);
	}
}

void	sort_stack(t_stack *a, t_stack *b, int length)
{
	if (length == 2)
	{
		ra(a);
		write(1, "ra\n", 3);
	}
	else if (length == 3)
		sort_length_3(a);
	else if (length == 4)
		sort_length_4(a, b);
	else if (length == 5)
		sort_length_5(a, b);
	else
		turk_sort(a, b);
}
