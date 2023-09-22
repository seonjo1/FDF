/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:02:41 by seonjo            #+#    #+#             */
/*   Updated: 2023/09/22 19:24:19 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_angle(t_map *map, double x, double y, double z)
{
	map->angle.x += x;
	map->angle.y += y;
	map->angle.z += z;
}

void	set_xyz(t_map *map, t_xyz *xyz)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		xyz[i].x = (map->map)[i].x;
		xyz[i].y = (map->map)[i].y;
		xyz[i].z = (map->map)[i].z;
		xyz[i].color = (map->map)[i].color;
		i++;
	}
}

void	draw_row(t_map *map, t_data *img, t_xyz *xyz, t_xyz offset)
{
	t_xyz	p0;
	t_xyz	p1;
	int		w;
	int		i;

	i = 0;
	w = map->width;
	while (i < map->size)
	{
		if ((i + 1) % w != 0)
		{
			p0.x = xyz[i].x + offset.x + map->move.x;
			p0.y = xyz[i].y + offset.y + map->move.y;
			p1.x = xyz[i + 1].x + offset.x + map->move.x;
			p1.y = xyz[i + 1].y + offset.y + map->move.y;
			if (p0.x <= p1.x)
				bresenham(img, p0, p1, xyz[i].color);
			else
				bresenham(img, p1, p0, xyz[i].color);
		}
		i++;
	}
}

void	draw_col(t_map *map, t_data *img, t_xyz *xyz, t_xyz offset)
{
	t_xyz	p0;
	t_xyz	p1;
	t_xyz	wh;
	t_xyz	ij;

	ij.x = 0;
	wh.x = map->width;
	wh.y = map->height;
	while (ij.x < wh.x)
	{
		ij.y = ij.x;
		while (ij.y / wh.x < wh.y - 1)
		{
			p0.x = xyz[(int)ij.y].x + offset.x + map->move.x;
			p0.y = xyz[(int)ij.y].y + offset.y + map->move.y;
			p1.x = xyz[(int)(ij.y + wh.x)].x + offset.x + map->move.x;
			p1.y = xyz[(int)(ij.y + wh.x)].y + offset.y + map->move.y;
			if (p0.x <= p1.x)
				bresenham(img, p0, p1, xyz[(int)ij.y].color);
			else
				bresenham(img, p1, p0, xyz[(int)ij.y].color);
			ij.y = ij.y + wh.x;
		}
		ij.x++;
	}
}

void	draw_img(t_map *map, t_data *img, int first)
{
	t_xyz	*xyz;
	t_xyz	offset;

	xyz = malloc(sizeof(t_xyz) * (map->size));
	if (xyz == NULL)
		exit(1);
	set_xyz(map, xyz);
	rotate(map, xyz, map->axis.x, map->axis.y);
	if (first)
		img_adjust(map, xyz);
	else
	{
		offset.x = 960 - map->axis.x;
		offset.y = 540 - map->axis.y;
		draw_row(map, img, xyz, offset);
		draw_col(map, img, xyz, offset);
	}
	free(xyz);
}
