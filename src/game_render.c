/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:51:34 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 20:34:12 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	map_collision(t_cub *cub, float next_x, float next_y)
{
	int	i;
	int	j;

	i = floor(next_x / TILE_SIZE);
	j = floor(next_y / TILE_SIZE);
	if ((cub->fmap->mat)[j][i] == '1')
		return (1);
	else
		return (0);
}

static void	update_player(t_cub *cub)
{
	int		forbidden;
	float	next_x;
	float	next_y;

	next_x = cub->p.x;
	next_y = cub->p.y;
	if (cub->p.w_dir)
	{
		next_x = cub->p.x + (cub->p.w_dir * cub->p.speed) * cos(cub->p.ang);
		next_y = cub->p.y + (cub->p.w_dir * cub->p.speed) * sin(cub->p.ang);
	}
	if (cub->p.w_side)
	{
		next_x = cub->p.x + (cub->p.w_side * cub->p.speed) \
			* cos(cub->p.ang + PIT);
		next_y = cub->p.y + (cub->p.w_side * cub->p.speed) \
			* sin(cub->p.ang + PIT);
	}
	forbidden = map_collision(cub, next_x, next_y);
	if (!forbidden)
	{
		cub->p.x = next_x;
		cub->p.y = next_y;
	}	
	cub->p.ang = cub->p.ang + cub->p.t_dir * cub->p.pi_speed;
}

static void	update(t_cub *cub)
{
	update_player(cub);
	cast_all_rays(cub);
}

int	render_game(t_cub *cub)
{
	update(cub);
	reset_frame(cub);
	if (cub->texture_opt)
		render_texture(cub);
	else
		render_walls(cub);
	if (cub->minimap_opt)
		render_minimap(cub);
	push_image(cub);
	return (0);
}
