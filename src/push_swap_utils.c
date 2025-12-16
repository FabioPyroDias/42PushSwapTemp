/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-cruz <fda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:53:01 by fda-cruz          #+#    #+#             */
/*   Updated: 2025/12/16 15:44:26 by fda-cruz         ###   ########.fr       */
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
	int	index;

	index = 0;
	while (start < length)
	{
		if (index == 0 && (str[index] == '+' || str[index] == '-'))
			return (0);
	}
	return (1);
}

int	count_numbers(char *str)
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
		while (str[index] || str[index] != ' ')
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

int	check_valid_numbers(char *argv[])
{
	int	index;
	int	index_c;

	index = 1;
	while (argv[index])
	{
		index_c = 0;
		while (argv[index][index_c])
		{
			if (!((argv[index][index_c] >= '0' && argv[index][index_c] <= '9') ||
				argv[index][index_c] == '+' || argv[index][index_c] == '-' ||
				(argv[index][index_c] >= 9 && argv[index][index_c] <= 13) ||
				argv[index][index_c] == ' '))
					return (0);
			index_c++;
		}
		index++;
	}
	return (1);
}

int	are_arguments_valid(int	argc, char *argv[], long **array)
{
	int	index;
	int	index_argv;

	index = 0;
	index_argv = 1;
	while (index < argc - 1)
	{
		*array[index] = ft_atol(argv[index_argv]);
		if (*array[index] < INT_MIN || *array[index] > INT_MAX)
		{
			write(2, "Error: Argument not within integer range\n", 41);
			return (0);
		}
		index++;
		index_argv++;
	}
	return (1);
}

/*
int	are_arguments_repeated(int argc, long **array)
{
	int	index;
	int	index_c;

	index = 0;
	while (index < argc - 2)
	{
		index_c = index + 1;
		while (index_c < argc - 1)
		{
			if (*array[index] == *array[index_c])
			{
				write(1, "Error: Duplicated arguments\n", 28);
				return (0);
			}
			index_c++;
		}
		index++;
	}
	return (1);
} */

int	is_valid_input(int argc, char *argv[])
{
	int	index;

	if (argc < 2)
	{
		write(2, "Error: Empty Stack\n", 19);
		return (0);
	}
	index = 1;
	while (argv[index])
	{
		if (ft_strlen(argv[index]) == 0)
			return (0);
		if (!count_numbers(argv[index]))
			return (0);
	}
}
