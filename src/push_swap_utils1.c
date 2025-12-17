#include "../include/push_swap.h"

int	is_valid_number(char *str, int *index)
{
	int	found_nbr;

	found_nbr = 0;
	while (str[*index] && !(str[*index] >= 9 && str[*index] <= 13) 
		&& str[*index] != ' ')
	{
		if ((str[*index] == '+' || str[*index] == '-'))
		{
			if (found_nbr)
				return (0);
			found_nbr = 1;
		}
		else if (str[*index] >= '0' && str[*index] <= '9')
			found_nbr = 1;
		else
			return (0);
		(*index)++;
	}
	return (found_nbr);
}

int	is_valid_argument(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			i++;
		if (str[i] == '\0')
			break ;
		if (!is_valid_number(str, &i))
			return (0);
		count++;
	}
	return (count);
}

int	count_numbers(int argc, char *argv[])
{
	int	count;
	int	current_count;
	int	i_arg;
	
	count = 0;
	i_arg = 1;
	while (i_arg < argc)
	{
		current_count = is_valid_argument(argv[i_arg]);
		if (current_count == 0)
			return (0);
		count += current_count;
		i_arg++;
	}
	return (count);
}

int	*parse_input(int argc, char *argv[])
{
	int	length;
	int	*array;

	if (argc < 2)
		return (write(2, "Error: Stack Empty\n", 19), NULL);
	length = count_numbers(argc, argv);
	if (length == 0)
		return (write(2, "Error: Invalid Input\n", 21), NULL);
	array = malloc(sizeof(int) * length);
	if (!array)
		return (write(2, "Error: Failed to Allocate Memory.\n", 34), NULL);
	if (!are_numbers_in_integer_range(array, argc, argv))
		return (write(2, "Error: Number not within Integer range\n", 39), NULL);
	if (!are_numbers_repeated(array, length))
		return (write(2, "Error: Duplicated Numbers\n", 26), NULL);
	return (array);
}
