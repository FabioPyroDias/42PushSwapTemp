/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:53:01 by fda-cruz          #+#    #+#             */
/*   Updated: 2025/12/15 21:06:23 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	check_valid_numbers(int argc, char *argv[])
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

int	is_valid_input(int argc, char *argv[])
{
	if (argc < 2)
	{
		write(2, "Error: Empty Stack\n", 19);
		return (0);
	}
	if (!check_valid_numbers)
	{
		write(2, "Error: Invalid Input\n", 21);
		return (0);
	}
}
