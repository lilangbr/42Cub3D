/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cast_one_v_hit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 20:58:58 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/23 01:31:17 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	v_intersection(int strip, t_cub *cub)
{
	cub->cast.itc.x = floor(cub->p.x / TILE_SIZE) * TILE_SIZE;
	if (cub->ray[strip].face_right == 1)
		cub->cast.itc.x = cub->cast.itc.x + TILE_SIZE;
	cub->cast.itc.y = cub->p.y + (cub->cast.itc.x - cub->p.x) * \
		tan(cub->ray[strip].ang);
	cub->cast.xstep = TILE_SIZE;
	if (cub->ray[strip].face_right == 0)
		cub->cast.xstep = cub->cast.xstep * (-1);
	cub->cast.ystep = TILE_SIZE * tan(cub->ray[strip].ang);
	if ((cub->ray[strip].face_up == 1) && (cub->cast.ystep > 0))
		cub->cast.ystep = cub->cast.ystep * (-1);
	if ((cub->ray[strip].face_up == 0) && (cub->cast.ystep < 0))
		cub->cast.ystep = cub->cast.ystep * (-1);
	cub->cast.next_v_touch.x = cub->cast.itc.x;
	cub->cast.next_v_touch.y = cub->cast.itc.y;
}

static void	collided(t_cub *cub)
{
	cub->cast.v_w_hit.x = cub->cast.next_v_touch.x;
	cub->cast.v_w_hit.y = cub->cast.next_v_touch.y;
	cub->cast.found_v_hit = 1;
}

void	v_find_a_wall(int strip, t_cub *cub)
{
	int	collision;

	while (cub->cast.next_v_touch.x >= 0 && cub->cast.next_v_touch.x <= \
		(cub->fmap->cols * TILE_SIZE) && cub->cast.next_v_touch.y >= 0 && \
			cub->cast.next_v_touch.y <= (cub->fmap->rows * TILE_SIZE))
	{
		cub->cast.to_check.x = cub->cast.next_v_touch.x;
		cub->cast.to_check.y = cub->cast.next_v_touch.y;
		if (cub->ray[strip].face_right == 0)
			cub->cast.to_check.x = cub->cast.to_check.x - 1;
		collision = map_collision(cub, cub->cast.to_check.x, \
			cub->cast.to_check.y);
		if (collision == 1)
		{
			collided(cub);
			break ;
		}
		else
		{
			cub->cast.next_v_touch.x = cub->cast.next_v_touch.x + \
				cub->cast.xstep;
			cub->cast.next_v_touch.y = cub->cast.next_v_touch.y + \
				cub->cast.ystep;
		}
	}
}
