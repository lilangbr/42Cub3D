/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:12:19 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 21:38:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	play(t_cub *cub)
{
	game_setup(cub);
	mlx_loop_hook(cub->mlx, render_game, cub);
	mlx_hook(cub->win, 2, 1L << 0, key_pressed, cub);
	mlx_hook(cub->win, 3, 1L << 1, key_released, cub);
	mlx_hook(cub->win, 33, 1L << 17, close_win, cub);
	mlx_loop(cub->mlx);
}
