/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 20:48:55 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 01:36:30 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	draw_mini_ray(t_cub *cub, int strip)
{
	int		side_lenght;
	float	x;
	float	y;
	int		i;

	if (fabs((cub->ray[strip].w_hit.x - cub->p.x)) >= \
		fabs((cub->ray[strip].w_hit.y - cub->p.y)))
		side_lenght = fabs((cub->ray[strip].w_hit.x - cub->p.x));
	else
		side_lenght = fabs((cub->ray[strip].w_hit.y - cub->p.y));
	x = cub->p.x;
	y = cub->p.y;
	i = 0;
	while (i <= side_lenght)
	{
		my_mlx_pixel_put(cub, round(x * MINIMAP_RATIO + cub->p.offset_mini), \
			round(y * MINIMAP_RATIO), PLAYER_COLOR);
		x = x + (cub->ray[strip].w_hit.x - cub->p.x) / (float)side_lenght;
		y = y + (cub->ray[strip].w_hit.y - cub->p.y) / (float)side_lenght;
		i = i + 1;
	}
	return (0);
}
