/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:23:45 by jperras           #+#    #+#             */
/*   Updated: 2022/03/22 17:47:08 by jperras          ###   ########.fr       */
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
			mlx_put_image_to_window(data->mlx, data->window.ref,
				data->image[0].ref, x, y);
			x = x - 1 + data->image[0].size.x;
		}
		y = y - 1 + data->image[0].size.y;
	}
}

static void	ft_put_sprite2(t_data *data, int i, int j)
{

	if (data->map.maps[i][j] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->window.ref,
				data->image[1].ref, (data->image[0].size.x) * j,
				(data->image[0].size.y) * i);
		data->position.x = data->image[0].size.x * j;
		data->position.y = data->image[0].size.y * i;
	}
	else if (data->map.maps[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->window.ref,
				data->image[2].ref,
				(data->image[0].size.x) * j, (data->image[0].size.y) * i);
	else if (data->map.maps[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->window.ref,
				data->image[3].ref,
				(data->image[0].size.x) * j, (data->image[0].size.y) * i);

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
				ft_put_sprite2(data, i, j);	
			else if (data->map.maps[i][j] == '1')
				ft_put_sprite2(data, i, j);
			else if (data->map.maps[i][j] == 'E')
				ft_put_sprite2(data, i, j);			
			else if (data->map.maps[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->window.ref,
					data->image[4].ref,
					(data->image[0].size.x) * j, (data->image[0].size.y) * i);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_put_image(t_data *data)
{
	data->image = malloc(sizeof(t_image) * 7);
	data->image[0] = ft_new_image(data->mlx, "image/Grass.xpm");
	data->image[1] = ft_new_image(data->mlx, "image/Players.xpm");
	data->image[2] = ft_new_image(data->mlx, "image/water.xpm");
	data->image[3] = ft_new_image(data->mlx, "image/Exit.xpm");
	data->image[4] = ft_new_image(data->mlx, "image/Tresor.xpm");
	data->image[5] = ft_new_image(data->mlx, "image/Tresorvide.xpm");
	data->image[6] = ft_new_image(data->mlx, "image/Sand.xpm");
}

t_image	ft_new_image(void *mlx, char *path)
{
	t_image	image;

	image.ref = mlx_xpm_file_to_image(mlx, path, &image.size.x, &image.size.y);
	return (image);
}
