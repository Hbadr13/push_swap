/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:43:56 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/13 23:47:15 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_push	*ft_lst_new(int val)
{
	t_push	*lst;

	lst = (t_push *) malloc(sizeof(t_push));
	if (!lst)
		exit (0);
	lst->content = val;
	lst->next = NULL;
	return (lst);
}

t_push	*return_lst_back(t_push **stack)
{
	t_push	*lst;

	lst = *stack;
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	lst_add_back(t_push **stack, t_push *lst)
{
	t_push	*node;

	if (!*stack)
	{
		*stack = lst;
		return ;
	}
	node = return_lst_back(stack);
	node->next = lst;
}

void	lst_add_frant(t_push **stack, t_push *lst)
{
	t_push	*swp;

	if (!*stack)
	{
		*stack = lst;
		return ;
	}
	swp = *stack;
	lst->next = swp;
	*stack = lst;
}

int	ft_lst_size(t_push **stack)
{
	t_push	*lst;
	int		i;

	i = 0;
	lst = *stack;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
