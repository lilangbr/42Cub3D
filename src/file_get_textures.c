/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_get_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 17:30:49 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 19:46:37 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	get_textures_core(char **line_read, t_cub *cub, char **str)
{
	if (**line_read != '\0')
	{
		if (**line_read == ' ' || **line_read == '\t')
		{
			strtrim_handled(line_read, " \t");
			strjoin_handled(line_read, str);
			if (*line_read == NULL)
			{
				close_and_free_fl(line_read, cub);
				error_handling(MALLOC_FAILED);
			}
		}
		else
		{
			close_and_free_fl(line_read, cub);
			error_handling(WRONG_IDENTIFIER);
		}
	}
	else
	{
		close_and_free_fl(line_read, cub);
		error_handling(MISSING_OPTIONS);
	}
}

static char	**choices(char **id, t_cub *cub, char k)
{
	if (k == 'N')
	{
		*id = "NO";
		return (&cub->file->t.no);
	}
	else if (k == 'S')
	{
		*id = "SO";
		return (&cub->file->t.so);
	}
	else if (k == 'W')
	{
		*id = "WE";
		return (&cub->file->t.we);
	}
	else
	{
		*id = "EA";
		return (&cub->file->t.ea);
	}
}

void	get_textures(char **line_read, t_cub *cub, char k)
{
	char	**text;
	char	*id;

	text = choices(&id, cub, k);
	if (**text == '\0')
	{
		strtrim_handled(line_read, " \t");
		strtrim_begin_handled(line_read, id);
		if (*line_read == NULL)
		{
			close_and_free_fl(line_read, cub);
			error_handling(MALLOC_FAILED);
		}
		get_textures_core(line_read, cub, text);
	}
	else
	{
		close_and_free_fl(line_read, cub);
		error_handling(DUPLICATE_IDENTIFIER);
	}
}
