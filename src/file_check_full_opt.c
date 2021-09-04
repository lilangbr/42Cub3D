/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_full_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:01:37 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/17 20:15:42 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	check_text(t_cub *cub)
{
	if ((*(cub->file->t.no) != '\0') && (*(cub->file->t.so) != '\0'))
		if ((*(cub->file->t.we) != '\0') && (*(cub->file->t.ea) != '\0'))
			return (1);
	return (0);
}

static int	check_floo(t_cub *cub)
{
	if ((cub->file->f.r != -1) && (cub->file->f.g != -1))
		if (cub->file->f.b != -1)
			return (1);
	return (0);
}

static int	check_ceil(t_cub *cub)
{
	if ((cub->file->c.r != -1) && (cub->file->c.g != -1))
		if (cub->file->c.b != -1)
			return (1);
	return (0);
}

int	check_full_options(t_cub *cub)
{
	if (check_text(cub))
		if (check_floo(cub) && check_ceil(cub))
			return (FULL_OPTIONS);
	return (NOT_FULL_OPTIONS);
}
