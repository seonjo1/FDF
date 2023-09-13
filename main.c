/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:05:01 by seonjo            #+#    #+#             */
/*   Updated: 2023/09/13 19:29:19 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//	char	*dst;

//	dst = data -> addr + (y * data->line_len + x * (data->bpp / 8));
//	*(unsigned int *)dst = color;
//}

//void	print_rainbow(t_data *img)
//{	
//	for (int i = 100; i < 200; i++)
//		for (int j = 0; j < 1920; j++)
//			ft_mlx_pixel_put(img, j, i, 0xff0000);		
//	for (int i = 200; i < 300; i++)
//		for (int j = 0; j < 1920; j++)
//			ft_mlx_pixel_put(img, j, i, 0xff7f00);		
//	for (int i = 300; i < 400; i++)
//		for (int j = 0; j < 1920; j++)
//			ft_mlx_pixel_put(img, j, i, 0xFFff00);		
//	for (int i = 400; i < 500; i++)
//		for (int j = 0; j < 1920; j++)
//			ft_mlx_pixel_put(img, j, i, 0x00ff00);		
//	for (int i = 500; i < 600; i++)
//		for (int j = 0; j < 1920; j++)
//			ft_mlx_pixel_put(img, j, i, 0x0000ff);		
//	for (int i = 600; i < 700; i++)
//		for (int j = 0; j < 1920; j++)
//			ft_mlx_pixel_put(img, j, i, 0x000080);		
//	for (int i = 700; i < 800; i++)
//		for (int j = 0; j < 1920; j++)
//			ft_mlx_pixel_put(img, j, i, 0x800080);		
//}

//int	close(int keycode, t_vars *vars)
//{
//	if (keycode == 53)
//		mlx_destroy_window(vars->mlx, vars->win);
//	return 0;
//}

#include <stdio.h>

//int print(int keycode)
//{
//	(void) keycode;
//	printf("1\n");
//	return (1);
//}

int	is_fdf(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		return (0);
	if (file[len - 1] != 'f')
		return (0);
	if (file[len - 2] != 'd')
		return (0);
	if (file[len - 3] != 'f')
		return (0);
	if (file[len - 4] != '.')
		return (0);
	return (1);
}

char	*ft_gnl(int fd)
{
	int		flag;
	char	*line;

	flag = 0;
	line = get_next_line(fd, &flag);
	if (flag == 1)
		exit(1);
	return (line);
}

void	get_width_height(t_map *map, int fd)
{
	int		i;
	char	*line;
	char	**line_split;

	line = ft_gnl(fd);
	line_split = ft_split(line, ' ');
	if (line_split == NULL)
		exit(1);
	i = 0;
	while (line_split[i] != NULL)
	{
		(map->width)++;
		free(line_split[i++]);
	}
	free(line_split);
	while (line != NULL)
	{
		(map->height)++;
		free(line);
		line = ft_gnl(fd);
	}
}

int	ft_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(1);
	return (fd);
}

void	malloc_map(t_map *map)
{
	int	i;
	int	h;

	map->map = malloc(sizeof(int *) * map->height);
	if (map->map == NULL)
		exit(1);
	i = 0;
	h = map->height;
	while (i < h)
	{
		(map->map)[i] = malloc(sizeof(int) * map->width);
		if ((map->map)[i] == NULL)
			exit(1);
		i++;
	}
}

void	fill_map(t_map *map, int fd)
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
			(map->map)[i][j] = ft_atoi(arr[j]);
			free(arr[j]);
			j++;
		}
		free(arr);
		free(line);
		i++;
		line = ft_gnl(fd);
	}
}

t_map	*get_map(char *file)
{
	t_map	*map;
	int		fd;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		exit(1);
	fd = ft_open(file);
	get_width_height(map, fd);
	close(fd);
	fd = ft_open(file);
	fill_map(map, fd);
	close(fd);
	return (map);
}

void	check_leak(void)
{
	system("leaks FDF");
}

int	main(int argc, char **argv)
{
	//t_vars	var;
	//t_data	img;
	t_map	*map;

	atexit(check_leak);
	if (argc != 2 || is_fdf(argv[1]) == 0)
		exit(1);
	map = get_map(argv[1]);

	//var.mlx = mlx_init();
	//var.win = mlx_new_window(var.mlx, 1920, 1080, "hello world!");
	//img.img = mlx_new_image(var.mlx, 1920, 1080);
	//img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	//print_rainbow(&img);
	//mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	//mlx_hook(var.win, 2, 0, close, 0);
	//mlx_hook(var.win, 25, 0, print, 0);
	//mlx_loop_hook(var.win, print, 0);
	//mlx_loop(var.mlx);
}
