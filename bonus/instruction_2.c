/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 08:58:14 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/14 06:51:30 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	sb(t_push **stack)
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
}

void	rb(t_push **stack)
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
}

void	rrb(t_push **stack)
{
	t_push	*lst;
	t_push	*mv;
	t_push	*swp;

	lst = NULL;
	mv = NULL;
	lst = *stack;
	swp = *stack;
	if (!lst || !lst->next)
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
}

void	pa(t_push **stack_a, t_push **stack_b)
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
}
