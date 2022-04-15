/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 07:36:31 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/13 08:48:59 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	return_position(t_push **stack, int min)
{
	t_push	*lst;
	int		n;
	int		i;

	i = 0;
	lst = *stack;
	while (lst)
	{
		if (lst->content == min)
			break ;
		i++;
		lst = lst->next;
	}
	n = ft_lst_size(stack);
	if (i > n / 2)
		return (0);
	return (1);
}

t_push	*return_min(t_push **stack)
{
	t_push	*min;
	t_push	*lst;

	lst = *stack;
	min = lst;
	while (lst)
	{
		if (lst->content < min->content)
			min = lst;
		lst = lst->next;
	}
	return (min);
}

t_push	*return_max(t_push **stack)
{
	t_push	*max;
	t_push	*lst;

	lst = *stack;
	max = lst;
	while (lst)
	{
		if (lst->content > max->content)
			max = lst;
		lst = lst->next;
	}
	return (max);
}

void	chick_number(t_push **stack)
{
	t_push	*node;
	t_push	*tode;
	int		conteur;

	node = *stack;
	while (node)
	{
		tode = *stack;
		conteur = 0;
		while (tode)
		{
			if (node->content == tode->content)
				conteur++;
			tode = tode->next;
		}
		if (conteur > 1)
		{
			write(2, "error", 5);
			exit(0);
		}
		node = node->next;
	}
}

void	free_stack(t_push **stack_a, t_push **stack_b)
{
	t_push	*lst;

	lst = *stack_a;
	while (lst)
	{
		free(lst);
		lst = lst->next;
	}
	free(stack_a);
	lst = *stack_b;
	while (lst)
	{
		free(lst);
		lst = lst->next;
	}
	free(stack_b);
}
