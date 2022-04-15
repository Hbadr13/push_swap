/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:06:19 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/13 09:03:22 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	ss(t_push **stack_a, t_push **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	rr(t_push **stack_a, t_push **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rrr(t_push **stack_a, t_push **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
