/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:06:32 by seonjo            #+#    #+#             */
/*   Updated: 2023/09/22 18:03:58 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "./libft/libft.h"
# include <math.h>

# define PI 3.14

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}t_data;

typedef struct s_xyz
{
	double	x;
	double	y;
	double	z;
}t_xyz;

typedef struct s_map
{
	t_xyz		*map;
	t_xyz		axis;
	t_xyz		angle;
	t_xyz		move;
	int			width;
	int			height;
	int			size;
	double		gap;
	double		og_gap;
}t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_data	img;
}t_vars;

char	*ft_gnl(int fd);
int		ft_open(char *file);
void	draw_img(t_map *map, t_data *img, int first);
void	img_adjust(t_map *map, t_xyz *xyz);
void	bresenham(t_data *img, t_xyz p0, t_xyz p1);
void	rotate(t_map *map, t_xyz *xyz, int axis_x, int axis_y);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	get_map(t_map *map, char *file);
int		key_hook(int keycode, t_vars *vars);
void	key_hook_move(int keycode, t_vars *vars);
void	key_hook_rotate(int keycode, t_vars *vars);
void	key_hook_scale(int keycode, t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
void	re_draw_img(t_vars *vars, int flag);
int		close_hook(t_vars *vars);
void	set_angle(t_map *map, double x, double y, double z);
void	isometric(t_vars *vars);
void	parallel(t_vars *vars);

#endif