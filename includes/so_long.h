/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:53:14 by jperras           #+#    #+#             */
/*   Updated: 2022/03/23 08:16:35 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../printf/includes/ft_printf.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include "get_next_line.h"
# include <fcntl.h>

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_windows
{
	void		*ref;
	t_vector	size;
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
	int		items;
	int		itemsc;
	int		itemsflag;
	int		win;

}	t_map;

typedef struct s_data
{
	void		*mlx;
	t_map		map;
	t_windows	window;
	t_image		*image;
	t_vector	position;

}	t_data;
typedef void	(*t_choose2)(t_data*, int*);
typedef void	(*t_choose3)(t_data*, int*, int);
/*
 *ft_windows.c, create windows
 *
 */
t_windows		ft_windows(void *mlx, int widht, int height, char *title);
/*
 *ft_image.c
 *
 */
t_image			ft_new_image(void *mlx, char *path);
void			ft_put_background(t_data *data);
void			ft_put_sprite(t_data *data);
void			ft_put_image(t_data *data);
/*
 *ft_hooks.c
 *
 */
int				ft_input(int key, t_data *data);
void			ft_up(t_data *data, int *count);
void			ft_left(t_data *data, int *count);
void			ft_right(t_data *data, int *count);
void			ft_down(t_data *data, int *count);
/*
 *ft_hooks2.c
 *
 */
void			ft_one(t_data *data, int *count, int postion);
void			ft_zero(t_data *data, int *count, int postion);
void			ft_e(t_data *data, int *count, int postion);
void			ft_c(t_data *data, int *count, int postion);
void			ft_putone(t_data *data, int position);
/*
 *ft_hooks3.c
 *
 */
void			ft_s(t_data *data, int *count, int postion);
void			ft_putto_window(t_data *data, int count);
/*
 *ft_map.c
 *
 */
int				ft_read_map(char *path, t_data *data);
/*
 *ft_map2.c
 *
 */
void			ft_readmap( t_data *data, char *path, int *flag);
#endif
