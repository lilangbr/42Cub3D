/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:58:03 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 22:06:08 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	key_released(int keycode, t_cub *cub)
{
	if (keycode == W_KEY || keycode == UP_KEY)
		cub->p.w_dir = 0;
	if (keycode == S_KEY || keycode == DOWN_KEY)
		cub->p.w_dir = 0;
	if (keycode == A_KEY)
		cub->p.w_side = 0;
	if (keycode == D_KEY)
		cub->p.w_side = 0;
	if (keycode == RIGHT_KEY)
		cub->p.t_dir = 0;
	if (keycode == LEFT_KEY)
		cub->p.t_dir = 0;
	return (0);
}

static int	key_pressed_bonus(int keycode, t_cub *cub)
{
	if (keycode == M_KEY)
	{
		if (cub->minimap_opt)
			cub->minimap_opt = 0;
		else
			cub->minimap_opt = 1;
	}
	if (keycode == T_KEY)
	{
		if (cub->texture_opt)
			cub->texture_opt = 0;
		else
			cub->texture_opt = 1;
	}
	return (0);
}

int	key_pressed(int keycode, t_cub *cub)
{
	if (keycode == ESC_KEY)
		close_win (cub);
	if (keycode == W_KEY || keycode == UP_KEY)
		cub->p.w_dir = 1;
	if (keycode == S_KEY || keycode == DOWN_KEY)
		cub->p.w_dir = -1;
	if (keycode == A_KEY)
		cub->p.w_side = -1;
	if (keycode == D_KEY)
		cub->p.w_side = 1;
	if (keycode == RIGHT_KEY)
		cub->p.t_dir = 1;
	if (keycode == LEFT_KEY)
		cub->p.t_dir = -1;
	if (keycode == M_KEY || keycode == T_KEY)
		key_pressed_bonus (keycode, cub);
	return (0);
}
