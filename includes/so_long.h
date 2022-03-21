/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:53:14 by jperras           #+#    #+#             */
/*   Updated: 2022/03/21 17:15:57 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"
# include <fcntl.h>

typedef void (*ft_choose)(int, char, t_data);

typedef struct s_vector 
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_windows
{
	void		*ref;
	t_vector 	size;
}	t_windows;

typedef struct s_image
{
	void		*ref;
	t_vector	size;
}	t_image;
typedef struct s_map
{
	char	**maps;
	int		line;
	int		col;

}	t_map;
typedef struct	s_data 
{
	void		*mlx;
	t_map		map;
	t_windows	window;
	t_image		*image;
	t_vector	position;

}	t_data;

/*
 *ft_windows.c, create windows
 *
 */
t_windows	ft_windows(void *mlx, int widht, int height, char *title);
/*
 *ft_image.c
 *
 */
t_image		ft_new_image(void *mlx, char *path);
void		ft_put_background(t_data *data);
void		ft_put_sprite(t_data *data);

/*
 *ft_hooks.c
 *
 */
int			ft_input(int key, t_data *data);
/*
 *ft_map.c
 *
 */
int			ft_check_map(char **map, int len, t_data *data);
int			ft_map_is_rectangle(char **map);
int			ft_read_map(char *path, t_data *data);
#endif
