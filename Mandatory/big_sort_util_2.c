/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_util_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 02:22:22 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/14 00:13:28 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_big(t_push **stack)
{
	t_push	*lst;

	lst = *stack;
	while (lst)
	{
		if (lst->index != 1)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	push_best_list_to_stack_b(t_push **stack_a, t_push **stack_b)
{
	t_push	*lst;
	int		pos;

	lst = *stack_a;
	cherch_list(stack_a);
	while (is_big(stack_a))
	{
		if (lst->index != 1)
		{
			pos = return_position(stack_a, lst->content);
			if (pos == 1)
				while ((*stack_a) != lst)
					ra(stack_a, 1);
			else
				while ((*stack_a) != lst)
					rra(stack_a, 1);
			pb(stack_a, stack_b, 1);
			lst = *stack_a;
		}
		else
			lst = lst->next;
	}
}

void	position_in_stack(t_push **stack_a, t_push **stack_b)
{
	int		size;
	t_push	*lst;
	int		i;

	lst = *stack_a;
	size = ft_lst_size(stack_a);
	i = 0;
	while ((i <= size / 2) && lst)
	{
		lst->pos = 1;
		lst = lst->next;
		i++;
	}
	lst = *stack_b;
	size = ft_lst_size(stack_b);
	i = 0;
	while ((i <= size / 2) && lst)
	{
		lst->pos = 1;
		lst = lst->next;
		i++;
	}
}

void	init_stack(t_push **stack_a, t_push **stack_b)
{
	t_push	*lst;

	lst = *stack_b;
	while (lst)
	{
		lst->pos = 0;
		lst->move = 0;
		lst->best_move = 0;
		lst = lst->next;
	}
	lst = *stack_a;
	while (lst)
	{
		lst->pos = 0;
		lst->move = 0;
		lst->best_move = 0;
		lst = lst->next;
	}
}
