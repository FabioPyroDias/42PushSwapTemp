/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:08:27 by fda-cruz          #+#    #+#             */
/*   Updated: 2025/12/17 22:59:00 by fabio            ###   ########.fr       */
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

int		is_valid_number(char *str, int *index);
int		is_valid_argument(char *str);
int		count_numbers(int argc, char *argv[]);
int		*parse_input(int argc, char *argv[]);
void	skip_spaces(char *str, int *index);
long	ft_atol(char *str, int *index);
int		is_number_in_integer_range(char *str, int *array, int *i_array);
int		are_numbers_in_integer_range(int *array, int argc, char *argv[]);
int		are_numbers_repeated(int *array, int length);

#endif