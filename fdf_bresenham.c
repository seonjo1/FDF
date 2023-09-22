/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:45:39 by seonjo            #+#    #+#             */
/*   Updated: 2023/09/19 16:18:44 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham_high_slope(t_data *img, t_xyz p0, t_xyz p1)
{
	t_xyz	p;
	t_xyz	dp;
	int		c;

	p.x = p0.x;
	p.y = p0.y;
	dp.x = p1.x - p0.x;
	dp.y = p1.y - p0.y;
	c = 2 * dp.x - dp.y;
	while (p.y <= p1.y)
	{
		ft_mlx_pixel_put(img, p.x, p.y, 0xFF0000);
		p.y++;
		if (c < 0)
			c = c + 2 * dp.x;
		else
		{
			c = c + 2 * dp.x - 2 * dp.y;
			p.x++;
		}
	}
}

void	bresenham_high_slope_rev(t_data *img, t_xyz p0, t_xyz p1)
{
	t_xyz	p;
	t_xyz	dp;
	int		c;

	p.x = p0.x;
	p.y = p0.y;
	dp.x = p1.x - p0.x;
	dp.y = p0.y - p1.y;
	c = 2 * dp.x - dp.y;
	while (p.y >= p1.y)
	{
		ft_mlx_pixel_put(img, p.x, p.y, 0xFF0000);
		p.y--;
		if (c < 0)
			c = c + 2 * dp.x;
		else
		{
			c = c + 2 * dp.x - 2 * dp.y;
			p.x++;
		}
	}
}

void	bresenham_low_slope(t_data *img, t_xyz p0, t_xyz p1)
{
	t_xyz	p;
	t_xyz	dp;
	int		c;

	p.x = p0.x;
	p.y = p0.y;
	dp.x = p1.x - p0.x;
	dp.y = p1.y - p0.y;
	c = 2 * dp.y - dp.x;
	while (p.x <= p1.x)
	{
		ft_mlx_pixel_put(img, p.x, p.y, 0xFF0000);
		p.x++;
		if (c < 0)
			c = c + 2 * dp.y;
		else
		{
			c = c + 2 * dp.y - 2 * dp.x;
			p.y++;
		}
	}
}

void	bresenham_low_slope_rev(t_data *img, t_xyz p0, t_xyz p1)
{
	t_xyz	p;
	t_xyz	dp;
	int		c;

	p.x = p1.x;
	p.y = p1.y;
	dp.x = p1.x - p0.x;
	dp.y = p0.y - p1.y;
	c = 2 * dp.y - dp.x;
	while (p.x >= p0.x)
	{
		ft_mlx_pixel_put(img, p.x, p.y, 0xFF0000);
		p.x--;
		if (c < 0)
			c = c + 2 * dp.y;
		else
		{
			c = c + 2 * dp.y - 2 * dp.x;
			p.y++;
		}
	}
}

void	bresenham(t_data *img, t_xyz p0, t_xyz p1)
{
	if (p1.y >= p0.y)
	{
		if (p1.y - p0.y > p1.x - p0.x)
			bresenham_high_slope(img, p0, p1);
		else
			bresenham_low_slope(img, p0, p1);
	}
	else
	{
		if (p0.y - p1.y > p1.x - p0.x)
			bresenham_high_slope_rev(img, p0, p1);
		else
			bresenham_low_slope_rev(img, p0, p1);
	}
}