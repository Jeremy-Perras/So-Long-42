/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 08:17:02 by jperras           #+#    #+#             */
/*   Updated: 2022/03/22 15:43:52 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_one(t_data *data, int *count, int position)
{
	(void) data;
	(void) count;
	(void) position;
}

void	ft_zero(t_data *data, int *count, int position)
{
	if(data->map.itemsflag)
		ft_putone(data, position);
	else
	{	
		mlx_put_image_to_window(data->mlx, data->window.ref, data->image[6].ref,
			data->position.x, data->position.y);
		mlx_put_image_to_window(data->mlx, data->window.ref, data->image[5].ref,
			data->position.x, data->position.y);
		data->map.itemsflag = 1;
	}
	if (position == 13)
		data->position.y -= data->image[0].size.y;
	else if (position == 0)
		data->position.x -= data->image[0].size.x;
	else if (position == 1)
		data->position.y += data->image[0].size.y;
	else if (position == 2)
		data->position.x += data->image[0].size.x;
	*count = *count + 1;
}

void	ft_c(t_data *data, int *count, int position)
{
	ft_putone(data, position);
	data->map.itemsflag = 0;
	data->map.itemsc = data->map.itemsc + 1;
	if (position == 13)
		data->position.y -= data->image[0].size.y;
	else if (position == 0)
		data->position.x -= data->image[0].size.x;
	else if (position == 1)
		data->position.y += data->image[0].size.y;
	else if (position == 2)
		data->position.x += data->image[0].size.x;
	*count = *count + 1;
}

void	ft_e(t_data *data, int *count, int position)
{
	if (data->map.items == data->map.itemsc)
	{
		ft_printf("You win with %d moves. Can you do better ?\n", *count);
		exit(0);
	}
	data->map.win = 1;
	(void) count;
	(void) position;
}

void	ft_putone(t_data *data, int position)
{
	int			x;
	int			y;
	int			width;
	int			lenght;

	x = data->position.x;
	y = data->position.y;
	width = data->image[0].size.y;
	lenght = data->image[0].size.x;
	if (position == 13)
		data->map.maps[(y / width) - 1][(x / lenght)] = '1';
	else if (position == 0)
		data->map.maps[(y / width)][(x / lenght) - 1] = '1';
	else if (position == 1)
		data->map.maps[(y / width) + 1][(x / lenght)] = '1';
	else if (position == 2)
		data->map.maps[(y / width)][(x / lenght) + 1] = '1';
	if(data->map.itemsflag)
		mlx_put_image_to_window(data->mlx, data->window.ref, data->image[6].ref,
			data->position.x, data->position.y);
}
