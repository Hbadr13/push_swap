/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 08:59:37 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/14 06:51:48 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	sa(t_push **stack)
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

void	ra(t_push **stack)
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

void	rra(t_push **stack)
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

void	pb(t_push **stack_a, t_push **stack_b)
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
}
