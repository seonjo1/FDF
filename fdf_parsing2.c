/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:27:22 by seonjo            #+#    #+#             */
/*   Updated: 2023/09/24 15:58:26 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	malloc_map(t_map *map)
{
	map->map = malloc(sizeof(t_map) * map->size);
	if (map->map == NULL)
		exit(1);
}

int	change_to_dec(char c)
{
	int		i;
	char	*digit;

	if ('a' <= c && c <= 'z')
		c -= 'a' - 'A';
	digit = "0123456789ABCDEF";
	i = 0;
	while (digit[i] != c)
		i++;
	return (i);
}

void	enter_value(t_xyz *xyz, char *input, int j, int k)
{
	int	i;
	int	dec;
	int	tmp;

	xyz->x = j;
	xyz->y = k;
	xyz->z = ft_atoi(input);
	i = 0;
	while (input[i] != '\0' && input[i++] != 'x')
		;
	if (input[i] == '\0')
		xyz->color = 0xFFFFFF;
	else
	{
		tmp = 0;
		while (input[i] != '\0' && input[i] != '\n')
		{
			dec = change_to_dec(input[i++]);
			tmp = tmp * 16 + dec;
		}
		xyz->color = tmp;
	}
}

void	fill_map(t_map	*map, int fd, int k)
{
	char	**arr;
	char	*line;
	int		i;
	int		j;

	malloc_map(map);
	line = ft_gnl(fd);
	i = 0;
	while (line != NULL)
	{
		arr = ft_split(line, ' ');
		j = 0;
		while (arr[j] != NULL)
		{
			if (arr[j][0] != '\n')
				enter_value(&((map->map)[i++]), arr[j], j, k);
			free(arr[j++]);
		}
		k++;
		free(arr);
		free(line);
		line = ft_gnl(fd);
	}
}
