/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:10:46 by fda-cruz          #+#    #+#             */
/*   Updated: 2025/12/28 17:18:52 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	int		*array;
	int		length;
	t_stack	*a;
	t_stack	*b;

	array = NULL;
	length = parse_input(argc, argv, &array);
	if (length == 0)
		return (free_all(NULL, NULL, array), 0);
	a = init_stack(array, length);
	b = init_stack(NULL, length);
	if (!a || !b)
		return (free_all(a, b, array), 0);
	if (is_sorted(array, length))
		return (free_all(a, b, array), 0);
	if (!normalize_array(a))
		return (free_all(a, b, array), 0);
	sort_stack(a, b, length);
	if (!is_sorted(a->array, length))
		return (free_all(a, b, array), 0);
	return (free_all(a, b, array), 0);
}
