/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:23:45 by jperras           #+#    #+#             */
/*   Updated: 2022/03/21 16:42:04 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->window.size.y)
	{
		x = 0;
		while (x < data->window.size.x)
		{
			mlx_put_image_to_window(data->mlx, data->window.ref, data->image[0].ref, x, y);
			x = x - 1+ data->image[0].size.x;
		}
		y = y - 1 + data->image[0].size.y;
	}
}

void	ft_put_sprite(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.maps[i])
	{
		while (data->map.maps[i][j])
		{
			if (data->map.maps[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->window.ref, data->image[0].ref,
						(data->image[0].size.x) * j, (data->image[0].size.y) * i);
				mlx_put_image_to_window(data->mlx, data->window.ref, data->image[1].ref,
						(data->image[0].size.x) * j, (data->image[0].size.y) * i);
			data->position.x = data->image[0].size.x * j;
			data->position.y = data->image[0].size.y * i;
			}
			else if (data->map.maps[i][j] == '1')
			{
				
				mlx_put_image_to_window(data->mlx, data->window.ref, data->image[2].ref,
						(data->image[0].size.x) * j, (data->image[0].size.y) * i);
			}
			else if (data->map.maps[i][j] == 'E')
			{
				
				mlx_put_image_to_window(data->mlx, data->window.ref, data->image[3].ref,
						(data->image[0].size.x) * j, (data->image[0].size.y) * i);
			}
			else if (data->map.maps[i][j] == 'C')
			{
				
				mlx_put_image_to_window(data->mlx, data->window.ref, data->image[4].ref,
						(data->image[0].size.x) * j, (data->image[0].size.y) * i);
			}


			j++;
		}
		j = 0;
		i++;
	}
}

t_image ft_new_image(void *mlx, char *path)
{
	t_image	image;
	
	image.ref = mlx_xpm_file_to_image(mlx, path, &image.size.x, &image.size.y);
	return (image);
}
