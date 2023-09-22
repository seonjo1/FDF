/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyhook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:52:29 by seonjo            #+#    #+#             */
/*   Updated: 2023/09/22 17:54:34 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_hook_scale(int keycode, t_vars *vars)
{
	double	scale;

	scale = (vars->map.gap) / 10;
	if (keycode == 12)
		vars->map.gap -= scale;
	else
		vars->map.gap += scale;
	//vars->map.axis.x = ((vars->map.width - 1) * vars->map.gap) / 2;
	//vars->map.axis.y = ((vars->map.height - 1) * vars->map.gap) / 2;
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
	if (keycode == 0)
		vars->map.move.x -= 10;
	else if (keycode == 2)
		vars->map.move.x += 10;
	else if (keycode == 13)
		vars->map.move.y -= 10;
	else
		vars->map.move.y += 10;
}