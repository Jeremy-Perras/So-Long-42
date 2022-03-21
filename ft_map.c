/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:47:21 by jperras           #+#    #+#             */
/*   Updated: 2022/03/21 15:25:48 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_check_map(char **map, int len, t_data *data)
{
	int	i;
	int	j;
	int	flag;
	int	col;

	i = 0;
	j = 0;
	flag = 1;
	while(map[0][j]  && flag)
	{
		if (map[0][j] != '1' || map[len][j] != '1')
			flag = 0;
		j++;	
	}
	col = j;
	data->map.col = j;
	i++;
	j = 0;
	while (map[i] && i < len && flag)
	{
		if (map[i][0] != '1' || map[i][col - 1] != '1')
			flag = 0;
		i++;
	}
	if (flag)
		return (1);
	return (0);
}

int ft_map_is_rectangle(char **map)
{
	int	i;
	int	len;
	int	tmp;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		tmp = ft_strlen(map[i]);
		if (tmp != len)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_read_map(char *path, t_data *data)
{
	int			fd;
	int			i;
	char		*tmp;
	int			flag;
	char		*tmp2;

	fd = open(path,O_RDONLY);
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
	data->map.maps = ft_split(tmp,'\n');
	flag = ft_map_is_rectangle(data->map.maps);
	flag = ft_check_map(data->map.maps, i, data);
	data->map.line = i;
	if (flag)
		return (1);
	return (0);

}
