/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_casting_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:09:46 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/28 23:25:33 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	cast_all_rays(t_cub *cub)
{
	float	ray_ang;
	int		strip;

	strip = 0;
	ray_ang = cub->p.ang - FOVT;
	while (strip < (cub->cast.sum))
	{
		ray_ang = normalize_angle(ray_ang);
		cast_one(ray_ang, strip, cub);
		ray_ang = ray_ang + (FOV / cub->cast.sum);
		strip = strip + 1;
	}
}
