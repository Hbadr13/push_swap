/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 06:43:03 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/13 07:34:12 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	**alloc_and_free_tab(int **tab, int size, int n)
{
	int	i;

	i = 0;
	if (n == 1)
	{
		tab = malloc (sizeof(int) * size * 4);
		while (i < size)
			tab[i++] = malloc (sizeof(int) * 4);
		return (tab);
	}
	if (n == 0)
	{
		while (i < size)
			free (tab[i++]);
		free (tab);
	}
	return (NULL);
}

void	init_tab(t_push **stack, int **tab)
{
	t_push	*lst;
	int		i;

	lst = *stack;
	i = 0;
	while (lst)
	{
		tab[i][0] = lst->content;
		tab[i][1] = 1;
		tab[i][2] = -1;
		tab[i++][3] = 0;
		lst = lst->next;
	}
}
