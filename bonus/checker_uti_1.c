/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_uti_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 09:23:38 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/13 09:29:23 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

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

void	print_error(t_push **stack_a, t_push **stack_b)
{
	free_stack(stack_a, stack_b);
	write(1, "error\n", 6);
	exit(0);
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
