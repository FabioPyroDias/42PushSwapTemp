#include "../include/checker.h"

int	main(int argc, char *argv[])
{
	int		*array;
	int		length;
	t_stack	*a;
	t_stack	*b;

	array = NULL;
	length = parse_input(argc, argv, &array);
	if (length == 0)
		return (free_all(NULL, NULL, array), write(1, "Error\n", 6), 0);
	a = init_stack(array, length);
	b = init_stack(NULL, length);
	if (!a || !b)
		return (free_all(a, b, array), write(1, "Error\n", 6), 0);
	if (is_sorted(array, length))
		return (free_all(a, b, array), write(1, "OK\n", 3), 0);
	if (!execute(a, b))
		return (free_all(a, b, array), write(1, "KO\n", 3), 0);
	if (!is_sorted(a->array, length))
		return (free_all(a, b, array), write(1, "KO\n", 3), 0);
	return (free_all(a, b, array), write(1, "OK\n", 3),  0);
}
