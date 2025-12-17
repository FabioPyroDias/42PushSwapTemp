/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:10:46 by fda-cruz          #+#    #+#             */
/*   Updated: 2025/12/17 21:49:54 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	int	*array;

	array = parse_input(argc, argv);
	if (!array)
		return (0);
	//Falta criar long array, passar todos os números para long,
	//1. Verificar se cabem em INT
	//2. Verificar se existe repetição
	(void) argv;
	return (0);
}
