/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:20:50 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/13 23:39:23 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct push_swap
{
	int					content;
	int					index;
	int					move;
	int					best_move;
	int					pos;
	struct push_swap	*brother;
	struct push_swap	*next;
}t_push;

int		main(int ac, char **argv);
void	chick_number(t_push **stack);
void	check_and_return_stack(t_push **stack, char **argv);
//r
t_push	*ft_lst_new(int val);
void	lst_add_back(t_push **stack, t_push *lst);
int		ft_lst_size(t_push **stack);
void	lst_add_frant(t_push **stack, t_push *lst);
t_push	*return_lst_back(t_push **stack);
void	cherch_list(t_push **stack);
void	printff(t_push **stack);
//util
t_push	*return_min(t_push **stack);
t_push	*return_max(t_push **stack);
int		return_position(t_push **stack, int min);
// operation
void	sa(t_push **stack, int flag);
void	ra(t_push **stack, int flag);
void	rra(t_push **stack, int flag);
void	pa(t_push **stack_a, t_push **stack_b, int flag);
void	pb(t_push **stack_a, t_push **stack_b, int flag);
void	sb(t_push **stack, int flag);
void	rb(t_push **stack, int flag);
void	rrb(t_push **stack, int flag);
void	ss(t_push **stack_a, t_push **stack_b, int flag);
void	rr(t_push **stack_a, t_push **stack_b, int flag);
void	rrr(t_push **stack_a, t_push **stack_b, int flag);
// sorted
void	sort_2(t_push **stack);
void	sort_3(t_push **stack);
void	sort_4(t_push **stack_a, t_push **stack_b);
void	sort_5(t_push **stack_a, t_push **stack_b);
void	big_sort(t_push **stack_a, t_push **stack_b);
int		is_big(t_push **stack);
void	push_best_list_to_stack_b(t_push **stack_a, t_push **stack_b);
void	position_in_stack(t_push **stack_a, t_push **stack_b);
void	init_stack(t_push **stack_a, t_push **stack_b);
void	number_of_move_in_a_b(t_push **stack_a, t_push **stack_b);
t_push	*best_move_in_stack(t_push **stack);
void	free_stack(t_push **stack_a, t_push **stack_b);
void	init_tab(t_push **stack, int **tab);
int		**alloc_and_free_tab(int **tab, int size, int n);

#endif 
