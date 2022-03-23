/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:54:42 by jperras           #+#    #+#             */
/*   Updated: 2022/03/23 08:44:03 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

t_choose2	g_cho2[] = {[0] = ft_left, [1] = ft_up, [2] = ft_right,
[13] = ft_down};
t_choose3	g_cho3[] = {['1'] = ft_one, ['0'] = ft_zero, ['E'] = ft_e,
['C'] = ft_c, ['P'] = ft_s};

int	ft_input(int key, t_data *data)
{
	static int	count;
	int			i;

	i = 0;
	if ((key >= 0 && key <= 3) || key == 13)
		g_cho2[key](data, &count);
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->window.ref);
		ft_printf("Too hard for you :) ?\n");
		exit (0);
	}
	while (data->map.maps[0][i])
	{
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[2].ref, data->image[0].size.x * i, 0);
		i++;
	}
	ft_putto_window(data, count);
	mlx_put_image_to_window(data->mlx, data->window.ref,
		data->image[1].ref, data->position.x, data->position.y);
	ft_printf("you have make :%d moves\n", count);
	return (0);
}

void	ft_up(t_data *data, int *count)
{	
	int			x;
	int			y;
	int			width;
	int			lenght;

	x = data->position.x;
	y = data->position.y;
	width = data->image[0].size.y;
	lenght = data->image[0].size.x;
	g_cho3[(int)(data->map.maps[(y / width) + 1][(x / lenght)])]
		(data, count, 1);
}

void	ft_left(t_data *data, int *count)
{
	int	x;
	int	y;
	int	width;
	int	lenght;

	x = data->position.x;
	y = data->position.y;
	width = data->image[0].size.y;
	lenght = data->image[0].size.x;
	g_cho3[(int)(data->map.maps[(y / width)][(x / lenght) - 1])]
		(data, count, 0);
}

void	ft_right(t_data *data, int *count)
{
	int			x;
	int			y;
	int			width;
	int			lenght;

	x = data->position.x;
	y = data->position.y;
	width = data->image[0].size.y;
	lenght = data->image[0].size.x;
	g_cho3[(int)(data->map.maps[(y / width)][(x / lenght) + 1])]
		(data, count, 2);
}

void	ft_down(t_data *data, int *count)
{	
	int			x;
	int			y;
	int			width;
	int			lenght;

	x = data->position.x;
	y = data->position.y;
	width = data->image[0].size.y;
	lenght = data->image[0].size.x;
	g_cho3[(int)(data->map.maps[(y / width) - 1][(x / lenght)])]
		(data, count, 13);
}
