/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:10:46 by fda-cruz          #+#    #+#             */
/*   Updated: 2025/12/21 21:10:16 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		*array;
	int		length;
	t_stack	*a;
	t_stack	*b;

	length = parse_input(argc, argv, &array);
	if (length == 0)
		return (free_all(NULL, NULL, array), 0);
	a = init_stack(array, length);
	b = init_stack(NULL, length);
	if (!a || !b)
		return (free_all(a, b, array), 0);
	if (is_sorted(array, length))
		return (free_all(a, b, array), write(1, "OK\n", 3), 0);
	sort_stack(a, b, length);
	/*unsigned int i = 0;
	while (i < a->size)
	{
		printf("%d ", a->array[i]);
		i++;
	}
	printf("\n"); */
	if (!is_sorted(a->array, length))
		return (free_all(a, b, array), write(1, "KO\n", 3), 0);
	return (free_all(a, b, array), write(1, "OK\n", 3), 0);
}
