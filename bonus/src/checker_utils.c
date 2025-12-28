#include "../include/checker.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	if (n == 0)
		return (0);
	index = 0;
	while (s1[index] && s2[index] && index < n - 1 && s1[index] == s2[index])
		index++;
	return ((unsigned char) s1[index] - (unsigned char) s2[index]);
}

int	apply_operation2(t_stack *a, t_stack *b, char *op, size_t line_size)
{
	if (!ft_strncmp("ra\n", op, line_size))
		rotate(a);
	else if (!ft_strncmp("rb\n", op, line_size))
		rotate(b);
	else if (!ft_strncmp("rr\n", op, line_size))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strncmp("rra\n", op, line_size))
		reverse_rotate(a);
	else if (!ft_strncmp("rrb\n", op, line_size))
		reverse_rotate(b);
	else if (!ft_strncmp("rrr\n", op, line_size))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		return (0);
	return (1);
}

int	apply_operation1(t_stack *a, t_stack *b, char *op)
{
	size_t	line_size;

	line_size = ft_strlen(op);
	if (line_size < 3 || line_size > 4)
		return (0);
	if (!ft_strncmp("sa\n", op, line_size))
		swap(a);
	else if (!ft_strncmp("sb\n", op, line_size))
		swap(b);
	else if (!ft_strncmp("ss\n", op, line_size))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strncmp("pa\n", op, line_size))
		push(a, b);
	else if (!ft_strncmp("pb\n", op, line_size))
		push(b, a);
	else
		return (apply_operation2(a, b, op, line_size));
	return (1);
}

int	execute(t_stack *a, t_stack *b)
{
	char	*line;

	line = NULL;
	line = get_next_line(0);
	while (line)
	{
		if (!apply_operation1(a, b, line))
			return (free(line), 0);
		free(line);
		line = get_next_line(0);
	}
	return (free(line), 1);
}
