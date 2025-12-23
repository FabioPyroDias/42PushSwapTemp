#include "../include/push_swap.h"

int	get_number_of_rotations_a(t_stack *a, int value)
{
	int	target;
	unsigned int	rotations;
	unsigned int	index;

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

void	get_number_of_rotations(t_stack *a, t_stack *b, unsigned int *a_i, unsigned int *b_i)
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

void	rotate_both_stacks(t_stack *a, t_stack *b, unsigned int *rot_a, unsigned int *rot_b)
{
	if (*rot_a <= a->size / 2 && *rot_b <= b->size / 2)
	{
		while (*rot_a > 0 && *rot_b > 0)
		{
			rr(a, b);
			(*rot_a)--;
			(*rot_b)--;
		}
	}
	else if(*rot_a > a->size / 2 && *rot_b > b->size / 2)
	{
		while (*rot_a < a->size && *rot_b < b->size)
		{
			rrr(a, b);
			(*rot_a)++;
			(*rot_b)++;
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
			if (passed_stack == 'a')
				rra(stack);
			else
				rrb(stack);
	}
}
#include <stdio.h>
void	turk_sort(t_stack *a, t_stack *b)
{
	unsigned int	rotation_a;
	unsigned int	rotation_b;
	unsigned int	min_value_index;

	while (a->size > 3)
		pb(b, a);
	unsigned int i = 0;
	printf("A: ");
	while (i < a->size)
	{
		printf("%d ", a->array[i]);
		i++;
	}
	printf("\n");
	i = 0;
	printf("B: ");
	while (i < b->size)
	{
		printf("%d ", b->array[i]);
		i++;
	}
	printf("\n");
	sort_length_3(a);
	printf("Apos ordenar:\n");
	printf("A: ");
	i = 0;
	while (i < a->size)
	{
		printf("%d ", a->array[i]);
		i++;
	}
	printf("\n");
	printf("\n");
	while (b->size != 0)
	{
		get_number_of_rotations(a, b, &rotation_a, &rotation_b);
		rotate_both_stacks(a, b, &rotation_a, &rotation_b);
		printf("Sai do Rotate Both Stacks:\n");
		printf("A: ");
		i = 0;
		while (i < a->size)
		{
			printf("%d ", a->array[i]);
			i++;
		}
		printf("\n");
		i = 0;
		printf("B: ");
		while (i < b->size)
		{
			printf("%d ", b->array[i]);
			i++;
		}
		printf("\n");
		rotate_stack(a, rotation_a, 'a');
		printf("Sai do Rotate Stack A:\n");
		printf("A: ");
		i = 0;
		while (i < a->size)
		{
		printf("%d ", a->array[i]);
		i++;
		}
		printf("\n");
		rotate_stack(b, rotation_b, 'b');
		printf("Sai do Rotate Stack B:\n");
		printf("B: ");
		i = 0;
		while (i < b->size)
		{
		printf("%d ", b->array[i]);
		i++;
		}
		printf("\n");
		pa(a, b);
		printf("Resultado ate agora:\n");
		printf("A: ");
		i = 0;
		while (i < a->size)
		{
		printf("%d ", a->array[i]);
		i++;
		}
		printf("\n\n");
	}
	min_value_index = get_min_value_index(a->array, a->size);
	if (min_value_index <= a->size / 2)
		while (min_value_index-- != 0)
			ra(a);
	else
		while (min_value_index++ != a->size)
			rra(a);
}
