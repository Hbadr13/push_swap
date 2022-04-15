/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:30:42 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/13 22:31:09 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_cont_in_save(char *var_sta)
{
	int		i;
	int		j;
	char	*src;

	i = 0;
	j = 0;
	while (var_sta[i] && var_sta[i] != '\n')
		i++;
	if (!var_sta[i])
		return (free(var_sta), NULL);
	src = (char *)malloc(sizeof(char) * (ft_str_len(var_sta) - i));
	if (!src)
		return (NULL);
	i++;
	while (var_sta[i])
	{
		src[j] = var_sta[i];
		j++;
		i++;
	}
	src[j] = '\0';
	free(var_sta);
	return (src);
}

char	*return_line(char *stac)
{
	char	*dst;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (stac[0] == '\0')
		return (NULL);
	while (stac[i] != '\n' && stac[i] != '\0')
		i++;
	if (stac[i] == '\n')
		i++;
	dst = malloc((sizeof(char)) * (i + 1));
	if (!dst)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dst[j] = stac[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char	*ft_read_and_save(char *stac, int fd)
{
	char	*buf;
	int		sz_return;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	sz_return = 1;
	while ((ft_newline(stac) == 0) && (sz_return != 0))
	{
		sz_return = read(fd, buf, BUFFER_SIZE);
		if (sz_return == -1)
		{
			free(buf);
			return (0);
		}
		buf[sz_return] = '\0';
		stac = ft_str_join(stac, buf);
	}
	free(buf);
	return (stac);
}

char	*get_next_line(int fd)
{
	static char	*var_static;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 10240)
		return (NULL);
	var_static = ft_read_and_save(var_static, fd);
	if (!var_static)
		return (NULL);
	line = return_line(var_static);
	var_static = save_cont_in_save(var_static);
	return (line);
}
