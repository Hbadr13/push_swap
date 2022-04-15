/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 05:58:53 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/14 02:26:23 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rb(t_push **stack, int flag)
{
	t_push	*lst;
	t_push	*mv;

	if (!*stack)
		return ;
	lst = *stack;
	mv = lst->next;
	*stack = mv;
	lst->next = NULL;
	lst_add_back(stack, lst);
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rrb(t_push **stack, int flag)
{
	t_push	*lst;
	t_push	*mv;
	t_push	*swp;

	lst = NULL;
	mv = NULL;
	lst = *stack;
	swp = *stack;
	if (!lst->next)
		return ;
	while (lst)
	{
		if (!lst->next->next)
		{
			mv = lst->next;
			lst->next = NULL;
			break ;
		}
		lst = lst->next;
	}
	mv->next = swp;
	*stack = mv;
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	pa(t_push **stack_a, t_push **stack_b, int flag)
{
	t_push	*lst;
	t_push	*mv;

	mv = NULL;
	if (!*stack_b)
		return ;
	lst = *stack_b;
	*stack_b = lst->next;
	lst->next = NULL;
	lst_add_frant(stack_a, lst);
	if (flag == 1)
		write(1, "pa\n", 3);
}
