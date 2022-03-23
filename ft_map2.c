/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:32:35 by jperras           #+#    #+#             */
/*   Updated: 2022/03/23 08:11:51 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_readmap(t_data *data, char *path, int *flag)
{
	int			fd;
	int			i;
	char		*tmp;
	char		*tmp2;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 1)
		*flag = 1;
	if (!*flag)
	{
		tmp = get_next_line(fd);
		tmp2 = get_next_line(fd);
		i = 0;
		while (tmp2)
		{
			tmp = ft_strjoin(tmp, tmp2);
			tmp2 = get_next_line(fd);
			i++;
		}
		close(fd);
		data->map.maps = ft_split(tmp, '\n');
		data->map.line = i;
	}
}
