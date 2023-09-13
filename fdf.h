/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:06:32 by seonjo            #+#    #+#             */
/*   Updated: 2023/09/13 18:56:23 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}t_data;

typedef struct s_map
{
	int		**map;
	int		width;
	int		height;
}t_map;

#endif