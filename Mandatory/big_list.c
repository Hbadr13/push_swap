/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:43:19 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/14 02:30:30 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	tableux_drem(int **tab, int index)
{
	int	i;

	i = 0;
	while (index != -1)
	{
		tab[index][3] = 1;
		index = tab[index][2];
		i++;
	}
}

int	find_max_list(int **tab, int size)
{
	int	i;
	int	index_max;
	int	max;

	i = 1;
	max = tab[0][1];
	index_max = 0;
	while (i < size)
	{
		if (tab[i][1] >= max)
		{
			index_max = i;
			max = tab[i][1];
		}
		i++;
	}
	return (index_max);
}

void	find_list(int **tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (tab[j][0] < tab[i][0])
			{
				if (tab[i][1] <= tab[j][1] + 1)
				{
					tab[i][1] = tab[j][1] + 1;
					tab[i][2] = j;
				}
			}
			j++;
		}
		i++;
	}
}

void	cherch_list(t_push **stack)
{
	int		i;
	t_push	*lst;
	int		**tab;
	int		size;

	size = ft_lst_size(stack);
	tab = NULL;
	tab = alloc_and_free_tab(tab, size, 1);
	i = 0;
	lst = *stack;
	init_tab(stack, tab);
	find_list(tab, size);
	i = find_max_list(tab, size);
	tableux_drem(tab, i);
	lst = *stack;
	i = 0;
	while (lst)
	{
		if (tab[i][3] == 1)
			lst->index = 1;
		i++;
		lst = lst->next;
	}
	alloc_and_free_tab(tab, size, 0);
}
