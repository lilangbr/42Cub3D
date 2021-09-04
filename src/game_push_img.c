/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_push_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:12:37 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 20:31:09 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	push_image(t_cub *cub)
{
	mlx_put_image_to_window(cub->mlx, cub->win, cub->data.img, 0, 0);
}
