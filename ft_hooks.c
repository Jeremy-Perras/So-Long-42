/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:54:42 by jperras           #+#    #+#             */
/*   Updated: 2022/03/19 17:40:19 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_input(int key, void *program)
{
	t_data	*data = (t_data *) program;

	mlx_clear_window(data->mlx, data->window.ref);
	if (key == 126)
			data->image[1].size.y -= data->image[1].size.y;
	mlx_put_image_to_window(data->mlx, data->window.ref,
		data->image[1].ref, data->image[1].size.x, data->image[1].size.y);
	



	return (0);
}	
