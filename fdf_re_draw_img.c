/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_re_draw_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:58:41 by seonjo            #+#    #+#             */
/*   Updated: 2023/09/22 16:59:46 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_img(t_data *img, t_vars vars)
{
	mlx_destroy_image(vars.mlx, img->img);
	img->img = mlx_new_image(vars.mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), \
				&(img->line_len), &(img->endian));
}

void	re_draw_img(t_vars *vars, int flag)
{
	make_img(&(vars->img), *vars);
	draw_img(&(vars->map), &(vars->img), flag);
	if (flag == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
