/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 05:18:21 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/14 02:21:24 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	big_sort_help_1(t_push **stack_a, t_push **stack_b, t_push *lst)
{
	int	n;
	int	conteur;

	if (lst->move < lst->brother->move)
	{
		n = lst->move;
		while (lst->move--)
			rr(stack_a, stack_b, 0);
		conteur = lst->brother->move - n;
		while (conteur--)
			ra(stack_a, 1);
	}
	else if (lst->move > lst->brother->move)
	{
		n = lst->brother->move;
		while (lst->brother->move--)
			rr(stack_a, stack_b, 0);
		conteur = lst->move - n;
		while (conteur--)
			rb(stack_b, 1);
	}
	else
		while (lst->move--)
			rr(stack_a, stack_b, 0);
}

void	big_sort_help_2(t_push **stack_a, t_push **stack_b, t_push *lst)
{
	int	n;
	int	conteur;

	if (lst->move < lst->brother->move)
	{
		n = lst->move;
		while (lst->move--)
			rrr(stack_a, stack_b, 0);
		conteur = lst->brother->move - n;
		while (conteur--)
			rra(stack_a, 1);
	}
	else if (lst->move > lst->brother->move)
	{
		n = lst->brother->move;
		while (lst->brother->move--)
			rrr(stack_a, stack_b, 0);
		conteur = lst->move - n;
		while (conteur--)
			rrb(stack_b, 1);
	}
	else
		while (lst->brother->move--)
			rrr(stack_a, stack_b, 0);
}

void	big_sort_help_3(t_push **stack_a, t_push **stack_b, t_push *lst)
{
	if (lst->pos == 1 && lst->brother->pos == 0)
	{
		while (lst->move--)
			rb(stack_b, 1);
		while (lst->brother->move--)
			rra(stack_a, 1);
	}
	else if (lst->pos == 0 && lst->brother->pos == 1)
	{
		while (lst->move--)
			rrb(stack_b, 1);
		while (lst->brother->move--)
			ra(stack_a, 1);
	}
}

void	fin_move(t_push **stack_a, t_push **stack_b)
{
	t_push	*lst;

	position_in_stack(stack_a, stack_b);
	lst = return_min(stack_a);
	while (*stack_a != lst)
	{
		if (lst->pos == 1)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
}

void	big_sort(t_push **stack_a, t_push **stack_b)
{
	t_push	*lst;

	push_best_list_to_stack_b(stack_a, stack_b);
	while (1)
	{
		init_stack(stack_a, stack_b);
		number_of_move_in_a_b(stack_a, stack_b);
		lst = best_move_in_stack(stack_b);
		if (lst->pos == 1 && lst->brother->pos == 1)
			big_sort_help_1(stack_a, stack_b, lst);
		else if (lst->pos == 0 && lst->brother->pos == 0)
			big_sort_help_2(stack_a, stack_b, lst);
		else
			big_sort_help_3(stack_a, stack_b, lst);
		pa(stack_a, stack_b, 1);
		if (!(*stack_b))
			break ;
	}
	fin_move(stack_a, stack_b);
}
