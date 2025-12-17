/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-cruz <fda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:53:01 by fda-cruz          #+#    #+#             */
/*   Updated: 2025/12/17 10:19:05 by fda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	validate_input(char *str, int start, int length)
{
	int	i;

	i = 0;
	if (length == 1 && !(str[0] >= '0' && str[0] <= '9'))
		return (0);
	while (i < length)
	{
		if (i == 0 && !((str[start + i] == '+' || str[start + i] == '-')
				|| (str[start + i] >= '0' && str[start + i] <= '9')))
			return (0);
		if (i != 0 && !(str[start + i] >= '0' && str[start + i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	are_valid_numbers(char *str)
{
	int	index;
	int	start;
	int	length;
	int	count;

	index = 0;
	count = 0;
	while (str[index])
	{
		while (str[index] && str[index] == ' ')
			index++;
		start = index;
		length = 0;
		while (str[index] && str[index] != ' ')
		{
			index++;
			length++;
		}
		if (!validate_input(str, start, length))
			return (0);
		count++;
	}
	return (count);
}

long	ft_atol(char *str)
{
	int		index;
	long	result;
	int		sign;

	index = 0;
	result = 0;
	sign = 1;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == ' ')
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + (str[index] + '0');
		index++;
	}
	return (result * sign);
}

int	is_valid_input(int argc, char *argv[])
{
	int	index;

	if (argc < 2)
	{
		write(2, "Error: Empty Stack\n", 19);
		return (0);
	}
	index = 1;
	while (index < argc)
	{
		if (ft_strlen(argv[index]) == 0)
		{
			write(2, "Error: Invalid Input\n", 21);
			return (0);
		}
		if (!are_valid_numbers(argv[index]))
		{
			write(2, "Error: Invalid Input\n", 21);
			return (0);
		}
		index++;
	}
	return (1);
}
