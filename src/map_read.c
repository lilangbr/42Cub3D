/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:02:23 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 21:13:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	read_map(char **line, t_cub *cub)
{
	strjoin_handled(line, &(cub->file->strmap));
	linemap_insert_star(&(cub->file->strmap));
	if (cub->file->strmap == NULL)
	{
		close_and_free_fl(line, cub);
		error_handling(MALLOC_FAILED);
	}
}
