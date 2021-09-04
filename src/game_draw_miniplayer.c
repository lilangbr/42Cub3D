/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw_miniplayer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:51:34 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 01:45:19 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	put_player_core(t_cub *cub, float i, float j)
{
	while (j < ((cub->p.y * MINIMAP_RATIO) - 1 + PLAYER_DIM))
	{
		while (i < ((cub->p.x * MINIMAP_RATIO) + cub->p.offset_mini - 1 \
			+ PLAYER_DIM))
		{
			if (j < 0)
				j = 0;
			else if (j > ((cub->fmap->rows * TILE_SIZE) * MINIMAP_RATIO))
				j = ((cub->fmap->rows * TILE_SIZE) * MINIMAP_RATIO);
			if (i < 0)
				i = 0;
			else if (i > (cub->fmap->cols * TILE_SIZE))
				i = (cub->fmap->cols * TILE_SIZE);
			my_mlx_pixel_put(cub, round(i), round(j), PLAYER_COLOR);
			i = i + 1;
		}
		i = (cub->p.x * MINIMAP_RATIO) + cub->p.offset_mini - 1;
		j = j + 1;
	}
	return (0);
}

int	put_player(t_cub *cub)
{
	float	i;
	float	j;

	i = (cub->p.x * MINIMAP_RATIO) + cub->p.offset_mini - 1;
	j = (cub->p.y * MINIMAP_RATIO) - 1;
	if (cub->p.x < 0 || cub->p.x > (cub->fmap->cols * TILE_SIZE) || \
		cub->p.y < 0 || cub->p.y > (cub->fmap->rows * TILE_SIZE))
		put_player_core(cub, i, j);
	return (0);
}

static int	put_player_dick_core(t_cub *cub, float x1, float y1)
{
	int		i;
	float	x;
	float	y;
	int		side_lenght;

	x = cub->p.x;
	y = cub->p.y;
	if (fabs(x1 - cub->p.x) >= fabs(y1 - cub->p.y))
		side_lenght = fabs(x1 - cub->p.x);
	else
		side_lenght = fabs(y1 - cub->p.y);
	i = 0;
	while (i <= side_lenght)
	{
		my_mlx_pixel_put(cub, round((x * MINIMAP_RATIO) + cub->p.offset_mini), \
		round(y * MINIMAP_RATIO), PLAYER_COLOR);
		x = x + ((x1 - cub->p.x) / (float)side_lenght);
		y = y + ((y1 - cub->p.y) / (float)side_lenght);
		i = i + 1;
	}
	return (0);
}

int	put_player_dick(t_cub *cub)
{
	float	x1;
	float	y1;

	x1 = cub->p.x + ((TILE_SIZE / 2) * cos(cub->p.ang));
	y1 = cub->p.y + ((TILE_SIZE / 2) * sin(cub->p.ang));
	put_player_dick_core(cub, x1, y1);
	return (0);
}
