/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img_adjust.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:16:37 by seonjo            #+#    #+#             */
/*   Updated: 2023/09/19 17:33:34 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_xyz	get_max(t_xyz *xyz, int size)
{
	t_xyz	max;
	int		i;

	max.x = xyz[0].x;
	max.y = xyz[0].y;
	i = 1;
	while (i < size)
	{
		if (xyz[i].x > max.x)
			max.x = xyz[i].x;
		if (xyz[i].y > max.y)
			max.y = xyz[i].y;
		i++;
	}
	return (max);
}

t_xyz	get_min(t_xyz *xyz, int size)
{
	t_xyz	min;
	int		i;

	min.x = xyz[0].x;
	min.y = xyz[0].y;
	i = 1;
	while (i < size)
	{
		if (xyz[i].x < min.x)
			min.x = xyz[i].x;
		if (xyz[i].y < min.y)
			min.y = xyz[i].y;
		i++;
	}
	return (min);
}

void	img_adjust(t_map *map, t_xyz *xyz)
{
	t_xyz	max;
	t_xyz	min;

	max = get_max(xyz, map->size);
	min = get_min(xyz, map->size);
	map->move.x = map->axis.x - (max.x + min.x) / 2;
	map->move.y = map->axis.y - (max.y + min.y) / 2;
}
