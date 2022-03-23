/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:25:35 by jperras           #+#    #+#             */
/*   Updated: 2022/03/23 08:18:11 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_initialisation(t_data *data)
{
	data->map.itemsflag = 1;
	data->map.itemsc = 0;
	data->map.items = 0;
	data->map.win = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		flag;

	data.mlx = mlx_init();
	flag = 0;
	ft_initialisation(&data);
	if (argc < 2 || ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		ft_printf("Error");
		return (0);
	}
	if (argc > 1)
		flag = ft_read_map(argv[1], &data);
	if (flag == 1 || data.map.line < 3 || data.map.col < 3)
	{
		ft_printf("Error");
		return (0);
	}
	ft_put_image(&data);
	data.window = ft_windows(data.mlx, data.map.col * data.image[0].size.x,
			(data.map.line + 1) * data.image[0].size.y, "Jack Sparrow");
	ft_put_background(&data);
	ft_put_sprite(&data);
	mlx_key_hook(data.window.ref, *ft_input, &data);
	mlx_loop(data.mlx);
}
