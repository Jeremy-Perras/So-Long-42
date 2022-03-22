/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:47:21 by jperras           #+#    #+#             */
/*   Updated: 2022/03/22 17:37:01 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	ft_map_is_rectangle(char **map);
static int	ft_check_map(char **map, int len, t_data *data);
static int	ft_check_start(char **map, t_data *data);
static int	ft_check_num(char **map);

static int	ft_check_map(char **map, int len, t_data *data)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 1;
	while (map[0][j] && flag)
	{
		if (map[0][j] != '1' || map[len][j] != '1')
			flag = 0;
		j++;
	}
	data->map.col = j;
	while (map[i] && i < len && flag)
	{
		if (map[i][0] != '1' || map[i][data->map.col - 1] != '1')
			flag = 0;
		i++;
	}
	if (!flag)
		return (1);
	return (0);
}

static int	ft_map_is_rectangle(char **map)
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
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_read_map(char *path, t_data *data)
{
	int			flag;
	
	flag = 0;
	ft_readmap(data, path, &flag);
	if (flag == 0)
		flag = ft_check_num(data->map.maps);
	if (flag == 0)
		flag = ft_map_is_rectangle(data->map.maps);
	if (flag == 0)
		flag = ft_check_map(data->map.maps,data->map.line, data);
	if (flag == 0)
		flag = ft_check_start(data->map.maps, data);	
	if (flag || !data->map.items)
		return (1);
	return (0);
}

static int	ft_check_num(char **map)
{
	int	j;
	int	i;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != '0' && map[i][j] != '1' &&
					map[i][j] != 'C')
				flag = 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (flag)
		return (1);
	return (0);
}

static int	ft_check_start(char **map, t_data *data)
{
	int	j;
	int	i;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'E')
				flag++;
			if(map[i][j] == 'C')
				data->map.items = data->map.items + 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (flag != 2)
		return (1);
	return (0);
}
