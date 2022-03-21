/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:54:42 by jperras           #+#    #+#             */
/*   Updated: 2022/03/21 17:14:48 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

ft_choose g_cho[]={['0']=ft_left,['1']=ft_up,['2']=ft_right,['13']=ft_down};

int	ft_input(int key, t_data *data)
{
	
	static int	count;
	int			x;
	int			y;
	int			width;
	int			lenght;
	
	x = data->position.x;
	y = data->position.y;
	width = data->image[0].size.y;
	lenght = data->image[0].size.x;
	mlx_put_image_to_window(data->mlx, data->window.ref,
		data->image[0].ref, data->position.x, data->position.y);
	if (key == 1 && data->map.maps[(y / width) + 1][(x / lenght)] != '1')
	{
		count ++;	
		data->position.y += data->image[0].size.y ;

	}
	if (key == 0 && data->map.maps[(y / width)][(x / lenght) - 1] != '1')
	{
			data->position.x -= data->image[0].size.x;
			count ++;
	}
	if (key == 2 && data->map.maps[(y / width)][(x / lenght) + 1] != '1')
	{
			data->position.x += data->image[0].size.x;
			count ++;
	}
	if (key == 13 && data->map.maps[(y / width) - 1][(x / lenght)] != '1')
	{	
		data->position.y -=  data->image[0].size.y;
		count ++;
	}
	mlx_put_image_to_window(data->mlx, data->window.ref,data->image[2].ref,0,0);
	mlx_string_put(data->mlx, data->window.ref, 0, 10,0xFFFFFF, ft_itoa(count));	
	mlx_put_image_to_window(data->mlx, data->window.ref,
		data->image[1].ref, data->position.x, data->position.y);
	printf("%d\n",count);
	return (0);
}
