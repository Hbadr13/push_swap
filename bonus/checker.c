/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 09:25:00 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/15 23:00:42 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "G_N_L/get_next_line.h"
#include "../libft/libft.h"

void	is_sort(t_push **stack_a, t_push **stack_b)
{
	t_push	*lst;

	lst = *stack_a;
	if (*stack_b)
	{
		write(1, "KO\n", 3);
		return ;
	}
	while (lst)
	{
		if (!lst->next)
			break ;
		if (lst->content > lst->next->content)
		{
			write(1, "KO\n", 3);
			return ;
		}
		lst = lst->next;
	}
	write(1, "OK\n", 3);
}

void	check_input_and_sort(t_push **stack_a, t_push **stack_b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		sa(stack_a);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb(stack_b);
	else if (!ft_strncmp(str, "ss\n", 3))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(str, "pa\n", 3))
		pa(stack_a, stack_b);
	else if (!ft_strncmp(str, "pb\n", 3))
		pb(stack_a, stack_b);
	else if (!ft_strncmp(str, "ra\n", 3))
		ra(stack_a);
	else if (!ft_strncmp(str, "rb\n", 3))
		rb(stack_b);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(str, "rra\n", 4))
		rra(stack_a);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rrb(stack_b);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr(stack_a, stack_b);
	else
		print_error(stack_a, stack_b);
}

int	main(int ac, char **argv)
{
	t_push	**stack_a;
	t_push	**stack_b;
	char	*str;

	if (ac < 2)
		return (0);
	stack_a = (t_push **)malloc(sizeof(t_push *));
	stack_b = (t_push **)malloc(sizeof(t_push *));
	*stack_b = NULL;
	*stack_a = NULL;
	stack_a = check_and_return_stack(stack_a, argv);
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		check_input_and_sort(stack_a, stack_b, str);
	}
	is_sort(stack_a, stack_b);
	free_stack(stack_a, stack_b);
	return (0);
}
