/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cast_one_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 20:58:58 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/23 01:31:17 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	pic_face_angle(float ray_ang, int strip, t_cub *cub)
{
	cub->ray[strip].ang = ray_ang;
	if (ray_ang > 0 && ray_ang < PI)
		cub->ray[strip].face_up = 0;
	else
		cub->ray[strip].face_up = 1;
	if (ray_ang < PIT || ray_ang > 3 * PIT)
		cub->ray[strip].face_right = 1;
	else
		cub->ray[strip].face_right = 0;
}

static void	cast_hit_init(t_cub *cub)
{
	cub->cast.found_h_hit = 0;
	cub->cast.h_w_hit.x = 0;
	cub->cast.h_w_hit.y = 0;
	cub->cast.found_v_hit = 0;
	cub->cast.v_w_hit.x = 0;
	cub->cast.v_w_hit.y = 0;
}

void	cast_one(float ray_ang, int strip, t_cub *cub)
{
	pic_face_angle(ray_ang, strip, cub);
	cast_hit_init(cub);
	h_intersection(strip, cub);
	h_find_a_wall(strip, cub);
	v_intersection(strip, cub);
	v_find_a_wall(strip, cub);
	calculate_hit_distances(cub);
	choising_distance(strip, cub);
}
