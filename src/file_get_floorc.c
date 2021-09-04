/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_get_floorc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 17:30:49 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 16:42:42 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	get_value(t_color *color, int opt, char **line_read, t_cub *cub )
{
	int	value;

	value = ft_atoi(*line_read);
	if (value > 255)
	{
		close_and_free_fl(line_read, cub);
		error_handling(WRONG_VALUE_OPTION);
	}
	if (opt == 3)
		color->r = value;
	else if (opt == 2)
		color->g = value;
	else
		color->b = value;
}

static void	clean_line(char **line_read, t_cub *cub, int opt)
{
	strtrim_begin_handled(line_read, "0123456789");
	strtrim_begin_handled(line_read, " \t");
	if (*line_read == NULL)
	{
		close_and_free_fl(line_read, cub);
		error_handling(MALLOC_FAILED);
	}
	if (opt == 1)
	{
		if (**line_read != '\0')
		{
			close_and_free_fl(line_read, cub);
			error_handling(WRONG_OPTIONS);
		}
	}
	else if (**line_read == ',' && opt != 1)
		str_cutfirsts_handled(line_read, 1);
	if (*line_read == NULL)
	{
		close_and_free_fl(line_read, cub);
		error_handling(MALLOC_FAILED);
	}
}

static void	define_error(char **line_read, t_cub *cub)
{
	if (**line_read == ',')
	{
		close_and_free_fl(line_read, cub);
		error_handling(WRONG_OPTIONS);
	}
	else
	{
		close_and_free_fl(line_read, cub);
		error_handling(INVALID_OPTION_NUMBER);
	}
}

static void	get_floorceiling_core(char **line_read, t_cub *cub, char k)
{
	int	option;

	option = 3;
	while (option > 0)
	{
		strtrim_handled(line_read, " \t");
		if (*line_read == NULL)
		{
			close_and_free_fl(line_read, cub);
			error_handling(MALLOC_FAILED);
		}
		if (ft_isdigit(**line_read))
		{
			if (k == 'F')
				get_value(&(cub->file->f), option, line_read, cub);
			else
				get_value(&(cub->file->c), option, line_read, cub);
			clean_line(line_read, cub, option);
		}
		else
			define_error(line_read, cub);
		option = option - 1;
	}
}

void	get_floorceiling(char **line_read, t_cub *cub, char k)
{
	if ((k == 'F' && cub->file->f.r != -1) || \
		(k == 'C' && cub->file->c.r != -1))
	{
		close_and_free_fl(line_read, cub);
		error_handling(DUPLICATE_IDENTIFIER);
	}
	else
	{
		strtrim_begin_handled(line_read, " \t");
		str_cutfirsts_handled(line_read, 1);
		if (*line_read == NULL)
		{
			close_and_free_fl(line_read, cub);
			error_handling(MALLOC_FAILED);
		}
		if (**line_read == '\0')
		{
			close_and_free_fl(line_read, cub);
			error_handling(MISSING_OPTIONS);
		}
		get_floorceiling_core(line_read, cub, k);
	}
}
