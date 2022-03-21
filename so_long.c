/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:25:35 by jperras           #+#    #+#             */
/*   Updated: 2022/03/21 16:49:29 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"





int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	ft_read_map("maps/map1.ber", &data);
	data.image = malloc(sizeof(t_image) * 6);
	data.image[0] = ft_new_image(data.mlx, "image/Grass.xpm");
	data.image[1] = ft_new_image(data.mlx, "image/Players.xpm");
	data.image[2] = ft_new_image(data.mlx, "image/water.xpm");
	data.image[3] = ft_new_image(data.mlx, "image/Exit.xpm");
	data.image[4] = ft_new_image(data.mlx, "image/Tresor.xpm");
	data.image[5] = ft_new_image(data.mlx, "image/Tresorvide.xpm");
	data.window = ft_windows(data.mlx,data.map.col * data.image[0].size.x,(data.map.line + 1) * data.image[0].size.y , "First test");

	ft_put_background(&data);
	ft_put_sprite(&data);
	mlx_key_hook(data.window.ref, *ft_input, &data);
	
	mlx_loop(data.mlx);
}


