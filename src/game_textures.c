/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:11:36 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 02:07:21 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	get_texture(t_text *text, t_cub *cub)
{
	text->data.img = mlx_xpm_file_to_image(cub->mlx, text->path, \
		&(text->width), &(text->height));
	if (!text->data.img)
		error_handling(WRONG_PATH);
	text->data.addr = mlx_get_data_addr(text->data.img, \
		&(text->data.bits_per_pixel), &(text->data.line_length), \
		&(text->data.endian));
}

void	create_textures(t_cub *cub)
{
	init_textures(cub);
	get_texture (&(cub->walls.text_n), cub);
	get_texture (&(cub->walls.text_s), cub);
	get_texture (&(cub->walls.text_w), cub);
	get_texture (&(cub->walls.text_e), cub);
}
