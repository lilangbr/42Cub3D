/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_minimap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:51:34 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/28 23:19:05 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	render_minimap(t_cub *cub)
{
	int	i;

	i = 0;
	put_minimap_bkg(cub);
	put_h_minigrid(cub);
	put_v_minigrid(cub);
	put_squares_on_grid(cub);
	put_player(cub);
	put_player_dick(cub);
	while (i < (cub->cast.sum))
	{
		draw_mini_ray(cub, i);
		i = i + 1;
	}
}
