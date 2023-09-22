/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:03:29 by seonjo            #+#    #+#             */
/*   Updated: 2023/09/22 17:30:23 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_map *map, t_xyz *xyz, int axis_y)
{
	t_xyz	tmp;
	double	theta;

	tmp.x = xyz->x;
	tmp.y = xyz->y - axis_y;
	tmp.z = xyz->z;
	theta = map->angle.x * (PI / 180);
	xyz->y = (tmp.y * cos(theta) - tmp.z * sin(theta)) + axis_y;
	xyz->z = tmp.y * sin(theta) + tmp.z * cos(theta);
}

void	rotate_y(t_map *map, t_xyz *xyz, int axis_x)
{
	t_xyz	tmp;
	double	theta;

	tmp.x = xyz->x - axis_x;
	tmp.y = xyz->y;
	tmp.z = xyz->z;
	theta = map->angle.y * (PI / 180);
	xyz->x = (tmp.x * cos(theta) + tmp.z * sin(theta)) + axis_x;
	xyz->z = tmp.z * cos(theta) - tmp.x * sin(theta);
}

void	rotate_z(t_map *map, t_xyz *xyz, int axis_x, int axis_y)
{
	t_xyz	tmp;
	double	theta;

	tmp.x = xyz->x - axis_x;
	tmp.y = xyz->y - axis_y;
	tmp.z = xyz->z;
	theta = map->angle.z * (PI / 180);
	xyz->x = (tmp.x * cos(theta) - tmp.y * sin(theta)) + axis_x;
	xyz->y = (tmp.x * sin(theta) + tmp.y * cos(theta)) + axis_y;
}

void	rotate(t_map *map, t_xyz *xyz, int axis_x, int axis_y)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		xyz[i].x *= map->gap;
		xyz[i].y *= map->gap;
		xyz[i].z *= map->gap;
		rotate_z(map, &xyz[i], axis_x, axis_y);
		rotate_x(map, &xyz[i], axis_y);
		rotate_y(map, &xyz[i], axis_x);
		i++;
	}
}
