/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:38:31 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/01/24 02:53:08 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int	*data;
	int	*sorted;
	int	*index_map;
	int	size;
	int	capacity;
}	t_stack;

// Utilitaires
int		ft_atoi(const char *str, int *error);
int		ft_isdigit(int c);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int		*parse_args(int argc, char **argv, int *error);

// Gestion des erreurs
void	error_exit(t_stack *a, t_stack *b, int *nums);

// Opérations
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// Tri
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
int		is_sorted(t_stack *a);

// Utilitaires de tri
int		find_min_index(t_stack *stack);
void	move_min_to_top_a(t_stack *a);
int		find_position(t_stack *a, int value);
void	move_to_top(t_stack *a, int pos);
void	move_second_min(t_stack *a, t_stack *b);

// Tri Radix
void	radix_sort(t_stack *a, t_stack *b);

// Utilitaires de tri
void	quicksort(int *arr, int size);

// Initialisation
void	init_stack_b(t_stack *a, t_stack *b, int argc);
void	create_index_map(t_stack *a, int argc);
void	init_stacks(t_stack *a, t_stack *b, int *nums, int argc);

#endif
