/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 22:42:25 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 21:04:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	fill_fmap(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < cub->fmap->rows)
	{
		while (i < cub->fmap->cols)
		{
			if ((cub->fmap->mat)[j][i] == ' ')
				(cub->fmap->mat)[j][i] = '1';
			i = i + 1;
		}
		i = 0;
		j = j + 1;
	}
}
