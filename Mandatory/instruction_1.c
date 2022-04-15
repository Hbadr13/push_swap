/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:06:19 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/14 02:22:03 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_push **stack, int flag)
{
	t_push	*lst;
	t_push	*swp;
	t_push	*mv;

	lst = *stack;
	if (!*stack)
		return ;
	if (!lst->next)
		return ;
	swp = lst->next;
	mv = lst->next->next;
	lst->next = mv;
	swp->next = lst;
	*stack = swp;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_push **stack, int flag)
{
	t_push	*lst;
	t_push	*swp;
	t_push	*mv;

	lst = *stack;
	if (!*stack)
		return ;
	if (!lst->next)
		return ;
	swp = lst->next;
	mv = lst->next->next;
	lst->next = mv;
	swp->next = lst;
	*stack = swp;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_push **stack_a, t_push **stack_b, int flag)
{
	sa(stack_a, flag);
	sb(stack_b, flag);
	write(1, "ss\n", 3);
}

void	rr(t_push **stack_a, t_push **stack_b, int flag)
{
	ra(stack_a, flag);
	rb(stack_b, flag);
	write(1, "rr\n", 3);
}

void	rrr(t_push **stack_a, t_push **stack_b, int flag)
{
	rra(stack_a, flag);
	rrb(stack_b, flag);
	write(1, "rrr\n", 4);
}
