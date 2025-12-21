/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:08:27 by fda-cruz          #+#    #+#             */
/*   Updated: 2025/12/21 20:21:40 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct stack
{
	unsigned int	size;
	unsigned int	capacity;
	int				*array;
}	t_stack;

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dst);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

int		is_valid_number(char *str, int *index);
int		is_valid_argument(char *str);
int		count_numbers(int argc, char *argv[]);
int		parse_input(int argc, char *argv[], int **array);

void	skip_spaces(char *str, int *index);
long	ft_atol(char *str, int *index);
int		is_number_in_integer_range(char *str, int *array, int *i_array);
int		are_numbers_in_integer_range(int *array, int argc, char *argv[]);
int		are_numbers_repeated(int *array, int length);

t_stack	*init_stack(int *array, int length);
int		is_sorted(int *array, int length);
void	free_all(t_stack *a, t_stack *b, int *array);
int		get_min_value_index(int	*array, int length);

void	sort_length_3(t_stack *a);
void	sort_length_4_base(t_stack *a, t_stack *b);
void	sort_length_4(t_stack *a, t_stack *b);
void	sort_stack(t_stack *a, t_stack *b, int length);

void	push_min_value_to_b(t_stack *a, t_stack *b, int index);
void	sort_length_5(t_stack *a, t_stack *b);

#endif