/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-cruz <fda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:10:46 by fda-cruz          #+#    #+#             */
/*   Updated: 2025/12/17 12:05:23 by fda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	if (!is_valid_input(argc, argv))
		return (0);
	if (!are_valid_nbrs(argc - 1, argv))
		return (0);
	//Falta criar long array, passar todos os números para long,
	//1. Verificar se cabem em INT
	//2. Verificar se existe repetição
	(void) argv;
	return (0);
}
