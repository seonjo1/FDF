/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img_adjust_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:16:37 by seonjo            #+#    #+#             */
/*   Updated: 2023/09/25 16:30:01 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_xyz	get_max(t_xyz *img_frame, int size)
{
	t_xyz	max;
	int		i;

	max.x = img_frame[0].x;
	max.y = img_frame[0].y;
	i = 1;
	while (i < size)
	{
		if (img_frame[i].x > max.x)
			max.x = img_frame[i].x;
		if (img_frame[i].y > max.y)
			max.y = img_frame[i].y;
		i++;
	}
	return (max);
}

t_xyz	get_min(t_xyz *img_frame, int size)
{
	t_xyz	min;
	int		i;

	min.x = img_frame[0].x;
	min.y = img_frame[0].y;
	i = 1;
	while (i < size)
	{
		if (img_frame[i].x < min.x)
			min.x = img_frame[i].x;
		if (img_frame[i].y < min.y)
			min.y = img_frame[i].y;
		i++;
	}
	return (min);
}

void	img_adjust(t_map *map, t_xyz *img_frame)
{
	t_xyz	max;
	t_xyz	min;

	max = get_max(img_frame, map->size);
	min = get_min(img_frame, map->size);
	map->move.x = map->axis.x - (max.x + min.x) / 2;
	map->move.y = map->axis.y - (max.y + min.y) / 2;
}
