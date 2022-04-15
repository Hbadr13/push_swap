/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:30:49 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/13 22:31:23 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_str_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_newline(char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i++])
			if (s[i] == '\n')
				return (1);
	return (0);
}

char	*ft_str_join(char *var_static, char *var)
{
	int			i;
	int			j;
	int			len;
	char		*nv_var;

	if (!var_static)
	{
		var_static = (char *)malloc(sizeof(char) * 1);
		var_static[0] = '\0';
	}
	if (!var_static || !var)
		return (NULL);
	len = ft_str_len(var) + ft_str_len(var_static);
	nv_var = malloc(sizeof(char) * (len + 1));
	if (!nv_var)
		return (NULL);
	i = -1;
	while (var_static[++i] != '\0')
			nv_var[i] = var_static[i];
	j = 0;
	while (var[j] != '\0')
		nv_var[i++] = var[j++];
	nv_var[i] = '\0';
	return (free(var_static), nv_var);
}
