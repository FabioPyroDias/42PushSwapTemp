#include "../include/push_swap.h"

void	sort_array(int	*array, unsigned int length)
{
	int	index;
	int	aux;

	index = 0;
	while ((unsigned int) index < length - 1)
	{
		if (array[index] > array[index + 1])
		{
			aux = array[index];
			array[index] = array[index + 1];
			array[index + 1] = aux;
			index--;
			if (index < 0)
				index = 0;
		}
		else
			index++;
	}
}

int	*create_sorted(int *array, unsigned int length)
{
	int				*sorted;
	unsigned int	index;

	sorted = malloc(sizeof(int) * length);
	if (!sorted)
		return (NULL);
	index = 0;
	while (index < length)
	{
		sorted[index] = array[index];
		index++;
	}
	sort_array(sorted, length);
	return (sorted);
}

int	normalize_array(t_stack *stack)
{
	int				*sorted;
	unsigned int	index;
	unsigned int	index2;

	sorted = create_sorted(stack->array, stack->size);
	if (!sorted)
		return (0);
	index = 0;
	while (index < stack->size)
	{
		index2 = 0;
		while (index2 < stack->size)
		{
			if (stack->array[index] == sorted[index2])
			{
				stack->array[index] = index2;
				break ;
			}
			index2++;
		}
		index++;
	}
	free(sorted);
	return (1);
}
