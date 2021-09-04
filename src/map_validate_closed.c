/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_closed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 00:15:40 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 21:17:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	jump_map_h(t_cub *cub, int j, int *i, char c)
{
	while (*i < cub->fmap->cols)
	{
		if ((cub->fmap->mat)[j][*i] == c)
			*i = *i + 1;
		else
		{
			if (c == '1')
				return (0);
			else if (c == ' ')
			{
				if ((cub->fmap->mat)[j][*i] == '0')
					return (1);
				else
					return (0);
			}
			else
			{
				if ((cub->fmap->mat)[j][*i] == ' ')
					return (1);
				else
					return (0);
			}
		}
	}
	return (0);
}

static int	jump_map_v(t_cub *cub, int *j, int i, char c)
{
	while (*j < cub->fmap->rows)
	{
		if ((cub->fmap->mat)[*j][i] == c)
			*j = *j + 1;
		else
		{
			if (c == '1')
				return (0);
			else if (c == ' ')
			{
				if ((cub->fmap->mat)[*j][i] == '0')
					return (1);
				else
					return (0);
			}
			else
			{
				if ((cub->fmap->mat)[*j][i] == ' ')
					return (1);
				else
					return (0);
			}
		}
	}
	return (0);
}

static int	go_right(t_cub *cub, int fail)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < cub->fmap->rows && !fail)
	{
		i = 0;
		while (i < cub->fmap->cols && !fail)
		{	
			if ((cub->fmap->mat)[j][i] == '1')
				fail = jump_map_h(cub, j, &i, '1');
			else if ((cub->fmap->mat)[j][i] == '0')
				fail = jump_map_h(cub, j, &i, '0');
			else if ((cub->fmap->mat)[j][i] == ' ')
				fail = jump_map_h(cub, j, &i, ' ');
			else
			{
				(cub->fmap->mat)[j][i] = 0;
				i = i + 1;
			}
		}
		j = j + 1;
	}
	return (fail);
}

static int	go_down(t_cub *cub, int fail)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < cub->fmap->cols && !fail)
	{
		j = 0;
		while (j < cub->fmap->rows && !fail)
		{
			if ((cub->fmap->mat)[j][i] == '1')
				fail = jump_map_v(cub, &j, i, '1');
			else if ((cub->fmap->mat)[j][i] == '0')
				fail = jump_map_v(cub, &j, i, '0');
			else if ((cub->fmap->mat)[j][i] == ' ')
				fail = jump_map_v(cub, &j, i, ' ');
			else
			{
				(cub->fmap->mat)[j][i] = 0;
				j = j + 1;
			}
		}
		i = i + 1;
	}
	return (fail);
}

int	opened_map(t_cub *cub)
{
	int	fail;

	fail = 0;
	fail = go_right(cub, 0);
	if (fail)
		return (1);
	fail = go_down(cub, 0);
	if (fail)
		return (1);
	return (0);
}
