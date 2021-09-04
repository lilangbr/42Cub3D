/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:51:34 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 01:47:14 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	put_square(t_cub *cub, float x, float y, float dim)
{
	float	xi;
	float	yi;

	xi = x;
	yi = y;
	if (xi < 0 || xi > ((cub->fmap->cols * TILE_SIZE) - dim) || yi < 0 || \
		yi > ((cub->fmap->rows * TILE_SIZE) - dim))
		return (-1);
	while (y < (yi + dim))
	{
		while (x < (xi + dim))
		{
			my_mlx_pixel_put(cub, round(x), round(y), MINIMAP_GCOLOR);
			x = x + 1;
		}
		x = xi;
		y = y + 1;
	}
	return (0);
}

int	put_v_minigrid(t_cub *cub)
{
	float	i;
	float	ii;
	int		j;
	int		count;

	count = 0;
	ii = (cub->fmap->cols * TILE_SIZE) - (cub->fmap->cols * TILE_SIZE * \
		MINIMAP_RATIO);
	i = ii;
	j = 0;
	while (count < cub->fmap->cols)
	{
		while (j < ((cub->fmap->rows) * TILE_SIZE * MINIMAP_RATIO))
		{
			my_mlx_pixel_put(cub, round(i), j, MINIMAP_GCOLOR);
			j = j + 1;
		}
		j = 0;
		count = count + 1;
		i = ii + count * TILE_SIZE * MINIMAP_RATIO;
	}
	return (0);
}

int	put_h_minigrid(t_cub *cub)
{
	float	j;
	int		ii;
	int		i;
	int		count;

	count = 0;
	j = 0;
	ii = (cub->fmap->cols * TILE_SIZE) - floor(cub->fmap->cols * \
		TILE_SIZE * MINIMAP_RATIO);
	i = ii;
	while (count <= cub->fmap->rows)
	{
		while (i < (ii + (cub->fmap->cols) * TILE_SIZE * MINIMAP_RATIO))
		{
			my_mlx_pixel_put(cub, i, round(j), MINIMAP_GCOLOR);
			i = i + 1;
		}
		i = ii;
		count = count + 1;
		j = count * TILE_SIZE * MINIMAP_RATIO;
	}
	return (0);
}

int	put_minimap_bkg(t_cub *cub)
{
	int	i;
	int	j;

	i = (cub->fmap->cols * TILE_SIZE) - floor(cub->fmap->cols * \
		TILE_SIZE * MINIMAP_RATIO);
	j = 0;
	while (j < ((cub->fmap->rows) * TILE_SIZE * MINIMAP_RATIO))
	{
		while (i < (cub->fmap->cols * TILE_SIZE))
		{
			my_mlx_pixel_put(cub, i, j, MINIMAP_BCOLOR);
			i = i + 1;
		}
		i = (cub->fmap->cols * TILE_SIZE) - floor(cub->fmap->cols \
		* TILE_SIZE * MINIMAP_RATIO);
		j = j + 1;
	}
	return (0);
}

int	put_squares_on_grid(t_cub *cub)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (row < cub->fmap->rows)
	{
		while (col < cub->fmap->cols)
		{
			if ((cub->fmap->mat)[row][col] == '1')
				put_square(cub, (((float)col * MINIMAP_RATIO * TILE_SIZE) \
				+ cub->p.offset_mini), ((float)row * MINIMAP_RATIO * \
				(float)TILE_SIZE), ((float)TILE_SIZE * MINIMAP_RATIO));
			col = col + 1;
		}
		col = 0;
		row = row + 1;
	}
	return (0);
}
