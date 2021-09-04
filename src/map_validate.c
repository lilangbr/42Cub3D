/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 00:15:40 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 21:24:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	validate_map(t_cub *cub)
{
	int	fail;

	fail = 0;
	if (wrong_h_limits(cub))
		fail = 1;
	else if (wrong_v_limits(cub))
		fail = 1;
	else if (more_players(cub))
		fail = 1;
	else if (opened_map(cub))
		fail = 1;
	if (fail)
	{
		close_and_free_fm(cub);
		error_handling(VALIDATE_MAP_FAIL);
	}
}
