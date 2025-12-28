#ifndef CHECKER_H
# define CHECKER_H

# include "../../include/push_swap.h"
# include "../../42Get_Next_Line/get_next_line.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	apply_operation2(t_stack *a, t_stack *b, char *op, size_t line_size);
int	apply_operation1(t_stack *a, t_stack *b, char *op);
int	execute(t_stack *a, t_stack *b);

#endif