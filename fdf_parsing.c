/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:55:22 by seonjo            #+#    #+#             */
/*   Updated: 2023/09/24 16:03:09 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_width_height(t_map *map, int fd, int i)
{
	char	*line;
	char	**width_split;

	map->height = 0;
	map->width = 0;
	line = ft_gnl(fd);
	width_split = ft_split(line, ' ');
	if (width_split == NULL)
		exit(1);
	i = 0;
	while (width_split[i] != NULL)
	{
		if (width_split[i][0] != '\n')
			(map->width)++;
		free(width_split[i++]);
	}
	free(width_split);
	while (line != NULL)
	{
		(map->height)++;
		free(line);
		line = ft_gnl(fd);
	}
	map->size = (map->height) * (map->width);
}

double	get_gap(t_map *map)
{
	double	gap;

	gap = 35;
	while (map->width * gap > 1920)
		gap--;
	while (map->height * gap > 1080)
		gap--;
	if (gap < 0)
		return (0);
	return (gap);
}

void	get_map(t_map *map, char *file)
{
	int		fd;

	fd = ft_open(file);
	get_width_height(map, fd, 0);
	close(fd);
	fd = ft_open(file);
	map->og_gap = get_gap(map);
	map->gap = map->og_gap;
	fill_map(map, fd, 0);
	close(fd);
	map->axis.x = ((map->width - 1) * map->gap) / 2;
	map->axis.y = ((map->height - 1) * map->gap) / 2;
	map->axis.z = 0;
	map->angle.x = 0;
	map->angle.y = 0;
	map->angle.z = 0;
	map->move.x = 0;
	map->move.y = 0;
	map->move.z = 0;
}
