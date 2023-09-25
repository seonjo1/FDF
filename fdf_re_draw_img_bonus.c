/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_re_draw_img_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:58:41 by seonjo            #+#    #+#             */
/*   Updated: 2023/09/25 16:23:26 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	make_img(t_data *img, t_vars vars)
{
	mlx_destroy_image(vars.mlx, img->img);
	img->img = mlx_new_image(vars.mlx, 1920, 1080);
	if (img->img == NULL)
		exit(1);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), \
				&(img->line_len), &(img->endian));
}

void	re_draw_img(t_vars *vars, int flag)
{
	make_img(&(vars->img), *vars);
	draw_img(vars, flag);
	if (flag == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
