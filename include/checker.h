/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:58:34 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/13 22:58:57 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct push_swap
{
	int					content;
	int					index;
	struct push_swap	*next;
}t_push;

int		main(int ac, char **av);
t_push	**check_and_return_stack(t_push **stack, char **argv);
t_push	*ft_lst_new(int val);
t_push	*return_lst_back(t_push **stack);
void	lst_add_back(t_push **stack, t_push *lst);
void	lst_add_frant(t_push **stack, t_push *lst);
int		ft_lst_size(t_push **stack);
void	chick_number(t_push **stack);
void	print_error(t_push **stack_a, t_push **stack_b);
void	free_stack(t_push **stack_a, t_push **stack_b);
void	print_error(t_push **stack_a, t_push **stack_b);
void	sa(t_push **stack);
void	ra(t_push **stack);
void	rra(t_push **stack);
void	pa(t_push **stack_a, t_push **stack_b);
void	pb(t_push **stack_a, t_push **stack_b);
void	sb(t_push **stack);
void	rb(t_push **stack);
void	rrb(t_push **stack);
void	ss(t_push **stack_a, t_push **stack_b);
void	rr(t_push **stack_a, t_push **stack_b);
void	rrr(t_push **stack_a, t_push **stack_b);

#endif
