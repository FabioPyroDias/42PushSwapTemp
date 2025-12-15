/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-cruz <fda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:53:01 by fda-cruz          #+#    #+#             */
/*   Updated: 2025/12/15 17:12:23 by fda-cruz         ###   ########.fr       */
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
		
	}
}
