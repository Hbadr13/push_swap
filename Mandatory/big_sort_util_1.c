/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_util_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 05:24:34 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/14 02:32:56 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_push	*best_move_in_stack_help(t_push **stack)
{
	t_push	*lst;
	t_push	*min;

	lst = *stack;
	min = lst;
	while (lst)
	{
		if (min->best_move > lst->best_move)
			min = lst;
		lst = lst->next;
	}
	return (min);
}

t_push	*best_move_in_stack(t_push **stack)
{
	t_push	*lst;

	lst = *stack;
	while (lst)
	{
		if (lst->pos == 1 && lst->brother->pos == 1)
		{
			if (lst->move > lst->brother->move)
				lst->best_move = lst->move;
			else if (lst->move <= lst->brother->move)
				lst->best_move = lst->brother->move;
		}
		else if (lst->pos == 0 && lst->brother->pos == 0)
		{
			if (lst->move > lst->brother->move)
				lst->best_move = lst->move;
			else if (lst->move <= lst->brother->move)
				lst->best_move = lst->brother->move;
		}
		else
			lst->best_move = lst->brother->move + lst->move;
		lst = lst->next;
	}
	return (best_move_in_stack_help(stack));
}

void	number_and_his_brother(t_push **stack_a, t_push *node)
{
	t_push	*lst;
	t_push	*end;

	lst = *stack_a;
	end = return_lst_back(stack_a);
	if (node->content < lst->content
		&& node->content > end->content)
		node->brother = lst;
	if (node->content > (return_max(stack_a))->content
		|| node->content < (return_min(stack_a))->content)
		node->brother = return_min(stack_a);
	while (lst && lst->next)
	{
		if (node->content > lst->content
			&& node->content < lst->next->content)
				node->brother = lst->next;
		lst = lst->next;
	}
}

void	number_of_move_in_a_b_help(t_push **stack_b)
{
	t_push	*lst;
	t_push	*node;

	node = *stack_b;
	lst = *stack_b;
	while (lst)
	{
		node = *stack_b;
		while (node != lst)
		{
			lst->move++;
			node = node->next;
		}
		if (lst->pos == 0)
			lst->move = ft_lst_size(stack_b) - lst->move;
		lst = lst->next;
	}
}

void	number_of_move_in_a_b(t_push **stack_a, t_push **stack_b)
{
	t_push	*node;
	t_push	*lst;

	node = *stack_b;
	while (node)
	{
		number_and_his_brother(stack_a, node);
		node = node->next;
	}
	position_in_stack(stack_a, stack_b);
	lst = *stack_a;
	while (lst)
	{
		node = *stack_a;
		while (node != lst)
		{
			lst->move++;
			node = node->next;
		}
		if (lst->pos == 0)
			lst->move = ft_lst_size(stack_a) - lst->move;
		lst = lst->next;
	}
	number_of_move_in_a_b_help(stack_b);
}
