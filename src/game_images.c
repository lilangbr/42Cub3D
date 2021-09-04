/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:51:34 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 20:30:34 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->data.addr + ((y * cub->data.line_length) + \
		(x * (cub->data.bits_per_pixel / 8 )));
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_pick(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * \
		(data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
