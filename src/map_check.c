/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 00:15:40 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 21:03:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	check_map_chars(t_cub *cub, char c)
{
	if (c == '\t')
	{
		close_and_free_fm(cub);
		error_handling(WRONG_MAP_TAB);
	}
	else if (c != ' ' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
	{
		if (c != '0' && c != '1')
		{
			close_and_free_fm(cub);
			error_handling(WRONG_MAP_CHAR);
		}
	}
}

void	check_map(t_cub *cub)
{
	char	c;
	int		i;
	int		j;

	fmap_in_heap(cub);
	init_fmap(cub);
	cub->fmap->mat = ft_split(cub->file->strmap, '*');
	if (!cub->fmap->mat)
	{
		close_and_free_fm(cub);
		error_handling(MALLOC_FAILED1);
	}
	i = 0;
	while ((cub->fmap->mat)[i] != NULL)
	{
		j = 0;
		while ((cub->fmap->mat)[i][j] != '\0')
		{
			c = (cub->fmap->mat)[i][j];
			check_map_chars(cub, c);
			j = j + 1;
		}
		i = i + 1;
	}
	return ;
}
