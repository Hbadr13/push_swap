/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 06:00:02 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/14 02:28:51 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_push **stack, int flag)
{
	t_push	*lst;
	t_push	*mv;

	lst = NULL;
	mv = NULL;
	if (!*stack)
		return ;
	lst = *stack;
	mv = lst->next;
	*stack = mv;
	lst->next = NULL;
	lst_add_back(stack, lst);
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rra(t_push **stack, int flag)
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
		write(1, "rra\n", 4);
}

void	pb(t_push **stack_a, t_push **stack_b, int flag)
{
	t_push	*lst;
	t_push	*mv;

	mv = NULL;
	if (!*stack_a)
		return ;
	lst = *stack_a;
	*stack_a = lst->next;
	lst->next = NULL;
	lst_add_frant(stack_b, lst);
	if (flag == 1)
		write(1, "pb\n", 3);
}
