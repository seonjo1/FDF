/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook_func_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:52:29 by seonjo            #+#    #+#             */
/*   Updated: 2023/09/27 22:26:28 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	isometric(t_vars *vars)
{
	vars->map.angle.x = 50;
	vars->map.angle.z = 45;
	vars->map.angle.y = 0;
	vars->map.move.x = 0;
	vars->map.move.y = 0;
	vars->map.move.y = 0;
	vars->map.gap = vars->map.og_gap;
	vars->map.axis.x = ((vars->map.width - 1) * vars->map.gap) / 2;
	vars->map.axis.y = ((vars->map.height - 1) * vars->map.gap) / 2;
}

void	parallel(t_vars *vars)
{
	vars->map.angle.x = 0;
	vars->map.angle.y = 0;
	vars->map.angle.z = 0;
	vars->map.move.x = 0;
	vars->map.move.y = 0;
	vars->map.move.y = 0;
	vars->map.gap = vars->map.og_gap;
	vars->map.axis.x = ((vars->map.width - 1) * vars->map.gap) / 2;
	vars->map.axis.y = ((vars->map.height - 1) * vars->map.gap) / 2;
}

void	key_hook_scale(int keycode, t_vars *vars)
{
	double	scale;

	scale = (vars->map.gap) / 10;
	if (keycode == 12)
		vars->map.gap -= scale;
	else
		vars->map.gap += scale;
	vars->map.axis.x = ((vars->map.width - 1) * vars->map.gap) / 2;
	vars->map.axis.y = ((vars->map.height - 1) * vars->map.gap) / 2;
}

void	key_hook_rotate(int keycode, t_vars *vars)
{
	if (keycode == 6)
		vars->map.angle.z += 5;
	else if (keycode == 7)
		vars->map.angle.x += 5;
	else
		vars->map.angle.y += 5;
}

void	key_hook_move(int keycode, t_vars *vars)
{
	int	move;

	move = vars->map.gap * 10;
	if (keycode == 0)
		vars->map.move.x -= move;
	else if (keycode == 2)
		vars->map.move.x += move;
	else if (keycode == 13)
		vars->map.move.y -= move;
	else
		vars->map.move.y += move;
}
