/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_windows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:36:15 by jperras           #+#    #+#             */
/*   Updated: 2022/03/19 11:14:38 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int ft_close()
{
	exit(0);
}

t_windows ft_windows(void *mlx, int widht, int height, char *title)
{
	t_windows	windows;

	windows.ref = mlx_new_window(mlx, widht, height, title);
	windows.size.x = widht;
	windows.size.y = height;

	mlx_hook(windows.ref , 17, 0, ft_close, 0);  
	return	(windows);
}
