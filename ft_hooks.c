/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:54:42 by jperras           #+#    #+#             */
/*   Updated: 2022/03/21 09:05:45 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_input(int key, t_data *data)
{
	
	static int	count;
	mlx_put_image_to_window(data->mlx, data->window.ref,
		data->image[0].ref, data->position.x, data->position.y);

	if (key == 1)
			data->position.y += data->image[1].size.y ;
	if (key == 0)
			data->position.x -= data->image[1].size.x;
	if (key == 2)
			data->position.x += data->image[1].size.x;
	if (key == 13)
			data->position.y -=  data->image[1].size.y;
	count ++;
	mlx_string_put(data->mlx, data->window.ref, 10, 10,0xFF0000 , "10");	
	mlx_put_image_to_window(data->mlx, data->window.ref,
		data->image[1].ref, data->position.x, data->position.y);
	printf("%d\n",count);
	return (0);
}
