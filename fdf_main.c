/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:05:01 by seonjo            #+#    #+#             */
/*   Updated: 2023/09/22 16:59:15 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2 || is_fdf(argv[1]) == 0)
		exit(1);
	get_map(&(vars.map), argv[1]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "window");
	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &(vars.img.bpp), \
					&(vars.img.line_len), &(vars.img.endian));
	set_angle(&(vars.map), 50, 0, 45);
	draw_img(&(vars.map), &(vars.img), 1);
	draw_img(&(vars.map), &(vars.img), 0);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_hook(vars.win, 2, 0, key_hook, (void *)(&vars));
	mlx_hook(vars.win, 4, 0, mouse_hook, (void *)(&vars));
	mlx_hook(vars.win, 17, 0, close_hook, (void *)(&vars));
	mlx_loop(vars.mlx);
}