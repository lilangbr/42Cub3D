/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:24:12 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/28 20:56:23 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	file_in_heap(t_cub *cub)
{
	cub->file = ft_calloc(1, (sizeof(t_file) + 1));
	if (cub->file == NULL)
		error_handling(MALLOC_FAILED1);
}

void	fmap_in_heap(t_cub *cub)
{
	cub->fmap = ft_calloc(1, (sizeof(t_fmap) + 1));
	if (cub->fmap == NULL)
	{
		free_file_content(cub);
		free(cub->file);
		error_handling(MALLOC_FAILED1);
	}
}

void	ray_in_heap(t_cub *cub)
{
	int		n_rays;

	n_rays = cub->fmap->cols * TILE_SIZE;
	cub->ray = ft_calloc(1, (sizeof(t_ray) * (n_rays + 1) + 1));
	if (!cub->ray)
	{
		close_and_free_fm(cub);
		if (cub->mlx)
			free(cub->mlx);
		error_handling(MALLOC_FAILED1);
	}
}
