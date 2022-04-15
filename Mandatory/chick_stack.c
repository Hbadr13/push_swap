/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chick_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:19:49 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/14 03:44:36 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static	void	print_error(void)
{
	write(2, "error", 5);
	exit(0);
}

static	void	ft_atoi_lite_help(char *str, int *i, long *nb)
{
	while (str[*i])
	{
		if (str[*i] < '0' || str[*i] > '9')
			print_error();
		*nb = *nb * 10 + str[*i] - '0';
		(*i)++;
	}
}

static	long	ft_atoi_lite(char	*str)
{
	int		sing;
	int		i;
	long	nb;

	nb = 0;
	sing = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\f'
		|| str[i] == '\v' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sing = sing * -1;
		i++;
	}
	if (!str[i])
		print_error();
	ft_atoi_lite_help(str, &i, &nb);
	if ((nb * sing) < -2147483648 || (nb * sing) > 2147483647)
		print_error();
	return (nb * sing);
}

void	check_and_return_stack(t_push **stack, char **argv)
{
	t_push	*node;
	char	**tab;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		tab = ft_split(argv[i], ' ');
		if (!tab[0])
			print_error();
		while (tab[j])
		{
			node = ft_lst_new(ft_atoi_lite(tab[j]));
			lst_add_back(stack, node);
			j++;
		}
		free_tab(tab);
		i++;
	}
	chick_number(stack);
}
