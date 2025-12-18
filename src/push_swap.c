/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-cruz <fda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:10:46 by fda-cruz          #+#    #+#             */
/*   Updated: 2025/12/18 11:10:48 by fda-cruz         ###   ########.fr       */
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
		return (0);
	a = init_stack(array, length);
	b = init_stack(NULL, length);
	if (!a || !b)
		return (0);
	if (is_sorted(array, length))
		return (free_all(a, b, array), write(1, "OK\n", 3), 0);
	return (free_all(a, b, array), 0);
}
