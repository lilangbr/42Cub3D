/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_limits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 00:15:40 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 21:19:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	wrong_h_limits(t_cub *cub)
{
	int	i;
	int	r;

	i = 0;
	r = cub->fmap->rows - 1;
	while (i < cub->fmap->cols)
	{
		if ((cub->fmap->mat)[0][i] != ' ' && (cub->fmap->mat)[0][i] != '1')
			return (1);
		if ((cub->fmap->mat)[r][i] != ' ' && (cub->fmap->mat)[r][i] != '1')
			return (1);
		i = i + 1;
	}
	return (0);
}

int	wrong_v_limits(t_cub *cub)
{
	int	i;
	int	c;

	i = 0;
	c = cub->fmap->cols - 1;
	while (i < cub->fmap->rows)
	{
		if ((cub->fmap->mat)[i][0] != ' ' && (cub->fmap->mat)[i][0] != '1')
			return (1);
		if ((cub->fmap->mat)[i][c] != ' ' && (cub->fmap->mat)[i][c] != '1')
			return (1);
		i = i + 1;
	}
	return (0);
}
