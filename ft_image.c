/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:23:45 by jperras           #+#    #+#             */
/*   Updated: 2022/03/19 17:20:17 by jperras          ###   ########.fr       */
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
	mlx_put_image_to_window(data->mlx, data->window.ref, data->image[1].ref, 0, 0);
}

t_image ft_new_image(void *mlx, char *path)
{
	t_image	image;

	image.ref = mlx_xpm_file_to_image(mlx, path, &image.size.x, &image.size.y);
	image.pixel = mlx_get_data_addr(image.ref, &image.bits_per_pixel, &image.line_size, &image.endian);
	return (image);
}
