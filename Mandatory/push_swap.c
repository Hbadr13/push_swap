/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 08:46:17 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/14 03:45:21 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	is_sort(t_push **stack_a, t_push **stack_b)
{
	t_push	*lst;
	int		conteur;

	lst = *stack_a;
	conteur = 1;
	while (lst && lst->next)
	{
		if (lst->content < lst->next->content)
			conteur++;
		lst = lst->next;
	}
	if (conteur == ft_lst_size(stack_a))
	{
		free_stack(stack_a, stack_b);
		exit(0);
	}	
}

void	sort_stack(t_push **stack_a, t_push **stack_b)
{
	int	size;

	size = ft_lst_size(stack_a);
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
}

int	main(int ac, char **argv)
{
	t_push	**stack_a;
	t_push	**stack_b;

	if (ac < 3)
		return (0);
	stack_a = (t_push **)malloc(sizeof(t_push *));
	stack_b = (t_push **)malloc(sizeof(t_push *));
	*stack_a = NULL;
	*stack_b = NULL;
	if (!stack_a || !stack_b)
		return (0);
	check_and_return_stack(stack_a, argv);
	is_sort(stack_a, stack_b);
	sort_stack(stack_a, stack_b);
	free_stack(stack_a, stack_b);
}
