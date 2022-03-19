/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:25:35 by jperras           #+#    #+#             */
/*   Updated: 2022/03/19 17:32:33 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"





int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.window = ft_windows(data.mlx, 1280, 720, "First test");
	data.image = malloc(sizeof(t_image) * 3);
	data.image[0] = ft_new_image(data.mlx, "image/Background.xpm");
	data.image[1] = ft_new_image(data.mlx, "image/Player.xpm");
	ft_put_background(&data);
	ft_put_sprite(&data);
	mlx_key_hook(data.window.ref, *ft_input, &data);
	
	
	
	
	mlx_loop(data.mlx);
}


