/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:36:12 by fda-cruz          #+#    #+#             */
/*   Updated: 2025/12/26 15:39:16 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	skip_spaces(char *str, int *index)
{
	while (str[*index] && ((str[*index] >= 9 && str[*index] <= 13)
			|| str[*index] == ' '))
		(*index)++;
}

long	ft_atol(char *str, int *index)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (str[*index] == '+' || str[*index] == '-')
	{
		if (str[*index] == '-')
			sign = -1;
		(*index)++;
	}
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		result = result * 10 + (str[*index] - '0');
		(*index)++;
	}
	return (result * sign);
}

int	is_number_in_integer_range(char *str, int *array, int *i_array)
{
	int		index;
	long	temp;

	index = 0;
	while (str[index])
	{
		skip_spaces(str, &index);
		if (str[index] == '\0')
			break ;
		temp = ft_atol(str, &index);
		if (temp < INT_MIN || temp > INT_MAX)
			return (0);
		array[*i_array] = (int) temp;
		(*i_array)++;
	}
	return (1);
}

int	are_nbrs_in_int_range(int *array, int argc, char *argv[])
{
	int		i_array;
	int		i_arg;

	i_array = 0;
	i_arg = 1;
	while (i_arg < argc)
	{
		if (!is_number_in_integer_range(argv[i_arg], array, &i_array))
			return (0);
		i_arg++;
	}
	return (1);
}

int	are_numbers_repeated(int *array, int length)
{
	int	i;
	int	i_c;

	i = 0;
	while (i < length - 1)
	{
		i_c = i + 1;
		while (i_c < length)
		{
			if (array[i] == array[i_c])
				return (0);
			i_c++;
		}
		i++;
	}
	return (1);
}
