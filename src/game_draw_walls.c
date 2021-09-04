/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:51:34 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 20:51:53 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	pic_color_wall(t_cub *cub, int i)
{
	if (cub->ray[i].w_hit_text == 'N')
		return (0x00512E5F);
	else if (cub->ray[i].w_hit_text == 'S')
		return (0x00154360);
	else if (cub->ray[i].w_hit_text == 'E')
		return (0x00646494);
	else
		return (0x002874A6);
}

int	draw_wall_strip_t(t_cub *cub, int strip)
{
	float	wall_strip_height;
	int		i;

	i = strip;
	wall_strip_height = ((TILE_SIZE / cub->ray[i].dist) * cub->p.pp_dist) \
		/cos(cub->ray[i].ang - cub->p.ang);
	if (wall_strip_height > (cub->fmap->rows * TILE_SIZE))
		wall_strip_height = cub->fmap->rows * TILE_SIZE;
	while (i < (strip + WALL_STRIP_WIDTH))
	{
		fill_texture(cub, strip);
		i = i + 1;
	}
	return (0);
}

int	draw_wall_strip(t_cub *cub, int strip)
{
	float	wall_strip_height;
	int		i;
	int		j;
	int		start_hemsi;

	i = strip;
	wall_strip_height = ((TILE_SIZE / cub->ray[i].dist) * cub->p.pp_dist) \
		/ cos(cub->ray[i].ang - cub->p.ang);
	if (wall_strip_height > (cub->fmap->rows * TILE_SIZE))
		wall_strip_height = cub->fmap->rows * TILE_SIZE;
	j = round(cub->fmap->rows * TILE_SIZE) / 2 - (wall_strip_height / 2);
	start_hemsi = j;
	while (j < start_hemsi + wall_strip_height)
	{
		while (i < (strip + WALL_STRIP_WIDTH))
		{
			my_mlx_pixel_put(cub, i, j, pic_color_wall(cub, i));
			i = i + 1;
		}
		i = strip;
		j = j + 1;
	}
	return (0);
}

void	render_texture(t_cub *cub)
{
	int	i;

	cub->p.pp_dist = (cub->fmap->cols * TILE_SIZE / 2) / tan(FOVT);
	i = 0;
	while (i < cub->cast.sum)
	{
		draw_wall_strip_t(cub, i);
		i = i + 1;
	}
}

void	render_walls(t_cub *cub)
{
	int	i;

	cub->p.pp_dist = (cub->fmap->cols * TILE_SIZE / 2) / tan(FOVT);
	i = 0;
	while (i < cub->cast.sum)
	{
		draw_wall_strip(cub, i);
		i = i + 1;
	}
}
