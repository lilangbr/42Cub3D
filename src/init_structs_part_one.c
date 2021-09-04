/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs_part_one.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:51:40 by user42            #+#    #+#             */
/*   Updated: 2021/08/30 20:56:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_cub(t_cub *cub)
{
	cub->file = NULL;
	cub->fmap = NULL;
	cub->mlx = NULL;
	cub->win = NULL;
	cub->ray = NULL;
	cub->minimap_opt = 0;
	cub->texture_opt = 1;
	cub->data.img = NULL;
	cub->data.addr = NULL;
	cub->walls.text_e.path = NULL;
	cub->walls.text_w.path = NULL;
	cub->walls.text_n.path = NULL;
	cub->walls.text_s.path = NULL;
	cub->walls.text_e.data.img = NULL;
	cub->walls.text_e.data.addr = NULL;
	cub->walls.text_w.data.img = NULL;
	cub->walls.text_w.data.addr = NULL;
	cub->walls.text_n.data.img = NULL;
	cub->walls.text_n.data.addr = NULL;
	cub->walls.text_s.data.img = NULL;
	cub->walls.text_s.data.addr = NULL;
	cub->ray = NULL;
}

void	init_cub_file(t_cub *cub)
{
	cub->file->fd = 0;
	cub->file->t.no = ft_strdup("");
	cub->file->t.so = ft_strdup("");
	cub->file->t.we = ft_strdup("");
	cub->file->t.ea = ft_strdup("");
	cub->file->f.r = -1;
	cub->file->f.g = -1;
	cub->file->f.b = -1;
	cub->file->c.r = -1;
	cub->file->c.g = -1;
	cub->file->c.b = -1;
	cub->file->strmap = ft_strdup("");
}

void	init_fmap(t_cub *cub)
{
	cub->fmap->mat = NULL;
}
