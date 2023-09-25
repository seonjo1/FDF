/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:03:29 by seonjo            #+#    #+#             */
/*   Updated: 2023/09/25 16:30:17 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_x(t_map *map, t_xyz *img_frame, int axis_y)
{
	t_xyz	tmp;
	double	theta;

	tmp.x = img_frame->x;
	tmp.y = img_frame->y - axis_y;
	tmp.z = img_frame->z;
	theta = map->angle.x * (PI / 180);
	img_frame->y = (tmp.y * cos(theta) - tmp.z * sin(theta)) + axis_y;
	img_frame->z = tmp.y * sin(theta) + tmp.z * cos(theta);
}

void	rotate_y(t_map *map, t_xyz *img_frame, int axis_x)
{
	t_xyz	tmp;
	double	theta;

	tmp.x = img_frame->x - axis_x;
	tmp.y = img_frame->y;
	tmp.z = img_frame->z;
	theta = map->angle.y * (PI / 180);
	img_frame->x = (tmp.x * cos(theta) + tmp.z * sin(theta)) + axis_x;
	img_frame->z = tmp.z * cos(theta) - tmp.x * sin(theta);
}

void	rotate_z(t_map *map, t_xyz *img_frame, int axis_x, int axis_y)
{
	t_xyz	tmp;
	double	theta;

	tmp.x = img_frame->x - axis_x;
	tmp.y = img_frame->y - axis_y;
	tmp.z = img_frame->z;
	theta = map->angle.z * (PI / 180);
	img_frame->x = (tmp.x * cos(theta) - tmp.y * sin(theta)) + axis_x;
	img_frame->y = (tmp.x * sin(theta) + tmp.y * cos(theta)) + axis_y;
}

void	rotate(t_map *map, t_xyz *img_frame, int axis_x, int axis_y)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		img_frame[i].x *= map->gap;
		img_frame[i].y *= map->gap;
		img_frame[i].z *= map->gap;
		rotate_z(map, &img_frame[i], axis_x, axis_y);
		rotate_x(map, &img_frame[i], axis_y);
		rotate_y(map, &img_frame[i], axis_x);
		i++;
	}
}
