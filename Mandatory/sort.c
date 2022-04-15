/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:18:37 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/13 08:49:20 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_4(t_push **stack_a, t_push **stack_b)
{
	t_push	*min;
	int		pos;

	min = return_min(stack_a);
	while ((*stack_a)->content != min->content)
	{
		pos = return_position(stack_a, min->content);
		if (pos == 1)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
	pb(stack_a, stack_b, 1);
	sort_3(stack_a);
	pa(stack_a, stack_b, 1);
}

void	sort_2(t_push **stack)
{
	t_push	*lst;

	lst = *stack;
	if (lst->content < lst->next->content)
		return ;
	else
		sa(stack, 1);
}

void	sort_3(t_push **stack)
{
	t_push	*lst;

	lst = *stack;
	if (lst->content > lst->next->content
		&& lst->content > lst->next->next->content)
		ra(stack, 1);
	lst = *stack;
	if (lst->content > lst->next->content)
		sa(stack, 1);
	lst = *stack;
	if (lst->content > lst->next->next->content
		&& lst->next->content > lst->next->next->content)
		rra(stack, 1);
	lst = *stack;
	if (lst->content < lst->next->next->content
		&& lst->next->content > lst->next->next->content)
	{
		rra(stack, 1);
		sa(stack, 1);
	}
}

void	sort_5_help(t_push **stack_a, t_push **stack_b)
{
	pb(stack_a, stack_b, 1);
	sort_3(stack_a);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
}

void	sort_5(t_push **stack_a, t_push **stack_b)
{
	t_push	*min;
	int		pos;
	int		i;

	i = 0;
	min = return_min(stack_a);
	while (1)
	{
		pos = return_position(stack_a, min->content);
		if (pos == 1)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
		if ((*stack_a)->content == min->content && i == 0)
		{
			pb(stack_a, stack_b, 1);
			min = return_min(stack_a);
			i++;
		}
		if ((*stack_a)->content == min->content)
			break ;
	}
	sort_5_help(stack_a, stack_b);
}
