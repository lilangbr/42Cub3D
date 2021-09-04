/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_fill_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 22:07:12 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 20:30:04 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	put_pixel_on_slice(t_cub *cub, int off_w, int strip, t_text *text)
{
	float	wall_strip_height;
	int		start_hemsi;
	int		j;
	int		end;

	wall_strip_height = ((TILE_SIZE / cub->ray[strip].dist) * cub->p.pp_dist) \
	/ cos(cub->ray[strip].ang - cub->p.ang);
	j = round(cub->fmap->rows * TILE_SIZE) / 2 - (wall_strip_height / 2);
	start_hemsi = j;
	end = start_hemsi + wall_strip_height;
	if (wall_strip_height > (cub->fmap->rows * TILE_SIZE))
	{
		end = cub->fmap->rows * TILE_SIZE;
		j = 0;
	}
	while (j < end)
	{
		my_mlx_pixel_put(cub, strip, j, my_mlx_pixel_pick (&(text->data), \
		off_w, ((j - start_hemsi) * text->height) / wall_strip_height));
		j = j + 1;
	}
}

static void	v_texture(t_cub *cub, int strip)
{
	int	x_text;

	if (cub->ray[strip].w_hit_text == 'W')
	{
		x_text = ((int)(round(cub->ray[strip].w_hit.y)) % \
			cub->walls.text_w.width);
		put_pixel_on_slice(cub, x_text, strip, &(cub->walls.text_w));
	}
	else
	{
		x_text = ((int)(round(cub->ray[strip].w_hit.y)) % \
			cub->walls.text_e.width);
		put_pixel_on_slice(cub, x_text, strip, &(cub->walls.text_e));
	}
}

static void	h_texture(t_cub *cub, int strip)
{
	int	x_text;

	if (cub->ray[strip].w_hit_text == 'N')
	{
		x_text = ((int)(round(cub->ray[strip].w_hit.x)) % \
			cub->walls.text_n.width);
		put_pixel_on_slice(cub, x_text, strip, &(cub->walls.text_n));
	}
	else
	{
		x_text = ((int)(round(cub->ray[strip].w_hit.x)) % \
			cub->walls.text_s.width);
		put_pixel_on_slice(cub, x_text, strip, &(cub->walls.text_s));
	}
}

void	fill_texture(t_cub *cub, int strip)
{
	if (cub->ray[strip].is_hit_v)
		v_texture (cub, strip);
	else
		h_texture (cub, strip);
}
