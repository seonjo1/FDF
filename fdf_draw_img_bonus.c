/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_img_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:02:41 by seonjo            #+#    #+#             */
/*   Updated: 2024/02/05 21:05:52 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	set_angle(t_map *map, double x, double y, double z)
{
	map->angle.x += x;
	map->angle.y += y;
	map->angle.z += z;
}

void	set_img_frame(t_map *map, t_xyz *img_frame)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		img_frame[i].x = (map->map)[i].x;
		img_frame[i].y = (map->map)[i].y;
		img_frame[i].z = (map->map)[i].z;
		img_frame[i].color = (map->map)[i].color;
		i++;
	}
}

void	draw_row(t_vars *vars, t_xyz *img_frame, double x_off, double y_off)
{
	t_xyz	p0;
	t_xyz	p1;
	int		w;
	int		i;

	w = vars->map.width;
	if (img_frame[0].z < img_frame[vars->map.size - 1].z)
	{
		i = 0;
		while (i < vars->map.size)
		{
			if ((i + 1) % w != 0)
			{
				p0.x = img_frame[i].x + x_off + vars->map.move.x;
				p0.y = img_frame[i].y + y_off + vars->map.move.y;
				p1.x = img_frame[i + 1].x + x_off + vars->map.move.x;
				p1.y = img_frame[i + 1].y + y_off + vars->map.move.y;
				if (p0.x <= p1.x)
					bresenham(&(vars->img), p0, p1, img_frame[i].color);
				else
					bresenham(&(vars->img), p1, p0, img_frame[i].color);
			}
			i++;
		}
	}
	else
	{
		i = vars->map.size - 1;
		while (i >= 0)
		{
			if ((i + 1) % w != 0)
			{
				p0.x = img_frame[i].x + x_off + vars->map.move.x;
				p0.y = img_frame[i].y + y_off + vars->map.move.y;
				p1.x = img_frame[i + 1].x + x_off + vars->map.move.x;
				p1.y = img_frame[i + 1].y + y_off + vars->map.move.y;
				if (p0.x <= p1.x)
					bresenham(&(vars->img), p0, p1, img_frame[i].color);
				else
					bresenham(&(vars->img), p1, p0, img_frame[i].color);
			}
			i--;
		}
	}
}

void	draw_col(t_vars *vars, t_xyz *img_frame, double x_off, double y_off)
{
	t_xyz	p0;
	t_xyz	p1;
	t_xyz	xy;
	int		w;

	if (img_frame[0].z < img_frame[vars->map.size - 1].z)
	{
		xy.x = 0;
		w = vars->map.width;
		while (xy.x < w)
		{
			xy.y = xy.x;
			while (xy.y / w < vars->map.height - 1)
			{
				p0.x = img_frame[(int)xy.y].x + x_off + vars->map.move.x;
				p0.y = img_frame[(int)xy.y].y + y_off + vars->map.move.y;
				p1.x = img_frame[(int)(xy.y + w)].x + x_off + vars->map.move.x;
				p1.y = img_frame[(int)(xy.y + w)].y + y_off + vars->map.move.y;
				if (p0.x <= p1.x)
					bresenham(&(vars->img), p0, p1, img_frame[(int)xy.y].color);
				else
					bresenham(&(vars->img), p1, p0, img_frame[(int)xy.y].color);
				xy.y = xy.y + w;
			}
			xy.x++;
		}
	}
	else
	{
		xy.x = vars->map.size - 1;
		w = vars->map.width;
		while (xy.x >= 0)
		{
			xy.y = xy.x;
			while (xy.y / w < vars->map.height - 1)
			{
				p0.x = img_frame[(int)xy.y].x + x_off + vars->map.move.x;
				p0.y = img_frame[(int)xy.y].y + y_off + vars->map.move.y;
				p1.x = img_frame[(int)(xy.y + w)].x + x_off + vars->map.move.x;
				p1.y = img_frame[(int)(xy.y + w)].y + y_off + vars->map.move.y;
				if (p0.x <= p1.x)
					bresenham(&(vars->img), p0, p1, img_frame[(int)xy.y].color);
				else
					bresenham(&(vars->img), p1, p0, img_frame[(int)xy.y].color);
				xy.y = xy.y + w;
			}
			xy.x--;
		}
	}
}

void	draw_img(t_vars *vars, int first)
{
	t_xyz	*img_frame;
	t_xyz	offset;

	img_frame = malloc(sizeof(t_xyz) * (vars->map.size));
	if (img_frame == NULL)
		exit(1);
	set_img_frame(&(vars->map), img_frame);
	rotate(&(vars->map), img_frame, vars->map.axis.x, vars->map.axis.y);
	if (first)
		img_adjust(&(vars->map), img_frame);
	else
	{
		offset.x = 960 - vars->map.axis.x;
		offset.y = 540 - vars->map.axis.y;
		draw_row(vars, img_frame, offset.x, offset.y);
		draw_col(vars, img_frame, offset.x, offset.y);
	}
	free(img_frame);
}
