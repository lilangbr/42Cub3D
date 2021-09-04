/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:23:30 by user42            #+#    #+#             */
/*   Updated: 2021/08/30 21:35:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	look_around(t_cub *cub, int i, int j)
{
	char	up;
	char	down;
	char	left;
	char	right;

	if (i == 0 || i == cub->fmap->cols || j == 0 || j == cub->fmap->rows)
	{
		close_and_free_fm(cub);
		error_handling(VALIDATE_MAP_FAIL);
	}
	else
	{
		up = (cub->fmap->mat)[j - 1][i];
		down = (cub->fmap->mat)[j + 1][i];
		left = (cub->fmap->mat)[j][i - 1];
		right = (cub->fmap->mat)[j][i + 1];
		if ((up != '0' && down != '0' && left != '0' && right != '0') || \
			(up == ' ' || down == ' ' || left == ' ' || right == ' '))
		{
			close_and_free_fm(cub);
			error_handling(VALIDATE_MAP_FAIL);
		}
	}
}

static void	capture_player(t_cub *cub, int posj, int posi)
{
	cub->fmap->p_posx = posi;
	cub->fmap->p_posy = posj;
	cub->fmap->p_dir = (cub->fmap->mat)[posj][posi];
}

static int	find_player(t_cub *cub)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	j = 0;
	count = 0;
	while (j < cub->fmap->rows)
	{
		while (i < cub->fmap->cols)
		{
			if ((cub->fmap->mat)[j][i] != ' ' && \
				(cub->fmap->mat)[j][i] != '1' && (cub->fmap->mat)[j][i] != '0')
			{
				capture_player(cub, j, i);
				look_around(cub, i, j);
				count = count + 1;
			}
			i = i + 1;
		}
		i = 0;
		j = j + 1;
	}
	return (count);
}

int	more_players(t_cub *cub)
{
	int	players;

	players = find_player(cub);
	if (players == 1)
		return (0);
	else
		return (1);
}
