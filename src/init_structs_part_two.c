/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs_part_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:11:36 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 20:56:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_player(t_cub *cub)
{
	cub->p.x = ((cub->fmap->p_posx) * TILE_SIZE) + (TILE_SIZE / 2);
	cub->p.y = ((cub->fmap->p_posy) * TILE_SIZE) + (TILE_SIZE / 2);
	cub->p.t_dir = 0;
	cub->p.w_dir = 0;
	cub->p.w_side = 0;
	if (cub->fmap->p_dir == 'S')
		cub->p.ang = PIT;
	else if (cub->fmap->p_dir == 'N')
		cub->p.ang = 3 * PIT;
	else if (cub->fmap->p_dir == 'E')
		cub->p.ang = 0;
	else
		cub->p.ang = PI;
	cub->p.speed = VLINEAR;
	cub->p.pi_speed = OMEGA;
	cub->p.offset_mini = (cub->fmap->cols * TILE_SIZE) - \
		(cub->fmap->cols * TILE_SIZE * MINIMAP_RATIO);
}

void	init_cast(t_cub *cub)
{
	cub->cast.sum = cub->fmap->cols * TILE_SIZE;
}

void	init_textures(t_cub *cub)
{
	cub->walls.text_n.path = cub->file->t.no;
	cub->walls.text_s.path = cub->file->t.so;
	cub->walls.text_w.path = cub->file->t.we;
	cub->walls.text_e.path = cub->file->t.ea;
}
