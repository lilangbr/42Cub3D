/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_reset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:33:43 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 20:39:34 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	paint_ceiling(t_cub *cub)
{
	int	x;
	int	y;
	int	bkgd;

	x = 0;
	y = 0;
	bkgd = create_trgb(1, cub->file->c.r, cub->file->c.g, cub->file->c.b);
	while (y < (cub->fmap->rows * TILE_SIZE) / 2)
	{
		while (x < (cub->fmap->cols * TILE_SIZE))
		{
			my_mlx_pixel_put(cub, x, y, bkgd);
			x = x + 1;
		}
		x = 0;
		y = y + 1;
	}
}

static void	paint_floor(t_cub *cub)
{
	int	x;
	int	y;
	int	bkgd;

	x = 0;
	y = (cub->fmap->rows * TILE_SIZE) / 2;
	bkgd = create_trgb(1, cub->file->f.r, cub->file->f.g, cub->file->f.b);
	while (y < (cub->fmap->rows * TILE_SIZE))
	{
		while (x < (cub->fmap->cols * TILE_SIZE))
		{
			my_mlx_pixel_put(cub, x, y, bkgd);
			x = x + 1;
		}
		x = 0;
		y = y + 1;
	}
}

void	reset_frame(t_cub *cub)
{
	paint_ceiling(cub);
	paint_floor(cub);
}
