/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:54:54 by seonjo            #+#    #+#             */
/*   Updated: 2023/09/25 16:21:39 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	key_hook_blackhole(t_vars *vars)
{
	while (vars->map.gap >= 0.00001)
	{
		vars->map.gap *= 0.95;
		key_hook_rotate(6, vars);
		re_draw_img(vars, 0);
	}
	isometric(vars);
	re_draw_img(vars, 1);
	re_draw_img(vars, 0);
	return (0);
}

int	close_hook(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == 1)
		isometric(vars);
	else if (button == 2)
		parallel(vars);
	else
		return (x);
	re_draw_img(vars, 1);
	re_draw_img(vars, 0);
	return (y);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_image(vars->mlx, vars->img.img);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == 0 || keycode == 2 || keycode == 13 || keycode == 1)
		key_hook_move(keycode, vars);
	else if (keycode == 6 || keycode == 7 || keycode == 8)
		key_hook_rotate(keycode, vars);
	else if (keycode == 12 || keycode == 14)
		key_hook_scale(keycode, vars);
	else if (keycode == 38)
		key_hook_blackhole(vars);
	re_draw_img(vars, 0);
	return (0);
}
