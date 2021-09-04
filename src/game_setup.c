/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:11:36 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 20:49:24 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	game_setup(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
	{
		close_and_free_fm(cub);
		error_handling(MINILIBX_INIT_FAIL);
	}
	init_player(cub);
	ray_in_heap(cub);
	init_cast(cub);
	cub->win = mlx_new_window(cub->mlx, cub->fmap->cols * TILE_SIZE, \
		cub->fmap->rows * TILE_SIZE, \
		"Thanks phemsi-a, romoreir and anolivei! (For you, my dad)");
	cub->data.img = mlx_new_image(cub->mlx, cub->fmap->cols * TILE_SIZE, \
		cub->fmap->rows * TILE_SIZE);
	cub->data.addr = mlx_get_data_addr(cub->data.img, \
		&(cub->data.bits_per_pixel), &(cub->data.line_length), \
		&(cub->data.endian));
	cast_all_rays(cub);
	create_textures(cub);
}
