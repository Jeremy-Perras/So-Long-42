/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:40:39 by jperras           #+#    #+#             */
/*   Updated: 2022/03/23 08:07:57 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_s(t_data *data, int *count, int position)
{
	(void) data;
	(void) count;
	(void) position;
}

void	ft_putto_window(t_data *data, int count)
{
	mlx_string_put(data->mlx, data->window.ref, 0, 10,
		0xFFFFFF, "You moved :");
	mlx_string_put(data->mlx, data->window.ref, 125, 10,
		0xFFFFFF, ft_itoa(count));
	mlx_string_put(data->mlx, data->window.ref, 0, 25,
		0xFFFFFF, "You have collected :");
	mlx_string_put(data->mlx, data->window.ref, 200, 25,
		0xFFFFFF, ft_itoa(data->map.itemsc));
	if (data->map.win == 1)
	{
		mlx_string_put(data->mlx, data->window.ref,
			data->window.size.x / 2 - 100, 10,
			0xFF0000, "Not enought collected");
		data->map.win = 0;
	}
}
