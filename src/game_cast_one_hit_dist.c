//* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cast_one_hit_dist.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 20:58:58 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/23 01:31:17 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	calculate_hit_distances(t_cub *cub)
{
	if (cub->cast.found_h_hit == 1)
		cub->cast.h_hit_dist = distance_of_pts(cub->p.x, cub->p.y, \
			cub->cast.h_w_hit.x, cub->cast.h_w_hit.y);
	else
		cub->cast.h_hit_dist = INT_MAX;
	if (cub->cast.found_v_hit == 1)
		cub->cast.v_hit_dist = distance_of_pts(cub->p.x, cub->p.y, \
			cub->cast.v_w_hit.x, cub->cast.v_w_hit.y);
	else
		cub->cast.v_hit_dist = INT_MAX;
}

void	choising_distance(int strip, t_cub *cub)
{
	if (cub->cast.v_hit_dist < cub->cast.h_hit_dist)
	{
		cub->ray[strip].dist = cub->cast.v_hit_dist;
		cub->ray[strip].w_hit.x = cub->cast.v_w_hit.x;
		cub->ray[strip].w_hit.y = cub->cast.v_w_hit.y;
		cub->ray[strip].is_hit_v = 1;
		if (cub->ray[strip].face_right == 1)
			cub->ray[strip].w_hit_text = 'W';
		else
			cub->ray[strip].w_hit_text = 'E';
	}
	else
	{
		cub->ray[strip].dist = cub->cast.h_hit_dist;
		cub->ray[strip].w_hit.x = cub->cast.h_w_hit.x;
		cub->ray[strip].w_hit.y = cub->cast.h_w_hit.y;
		cub->ray[strip].is_hit_v = 0;
		if (cub->ray[strip].face_up == 1)
			cub->ray[strip].w_hit_text = 'S';
		else
			cub->ray[strip].w_hit_text = 'N';
	}
}
