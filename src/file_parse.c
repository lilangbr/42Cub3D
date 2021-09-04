/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:12:08 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 20:04:19 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	aux_textures(char **line_read, t_cub *cub, int i)
{
	char	*l;

	l = *line_read;
	if (l[i] == 'N' && l[i + 1] == 'O')
		get_textures(line_read, cub, 'N');
	else if (l[i] == 'S' && l[i + 1] == 'O')
		get_textures(line_read, cub, 'S');
	else if (l[i] == 'W' && l[i + 1] == 'E')
		get_textures(line_read, cub, 'W');
	else if (l[i] == 'E' && l[i + 1] == 'A')
		get_textures(line_read, cub, 'E');
	else
		error_handling(WRONG_IDENTIFIER);
}

static int	parse_file_aux(char **line_read, t_cub *cub, char c, char d)
{
	if (c == 'F' && (d == ' ' || d == '\t' || d == '\0'))
		get_floorceiling(line_read, cub, 'F');
	else if (c == 'C' && (d == ' ' || d == '\t' || d == '\0'))
		get_floorceiling(line_read, cub, 'C');
	else if (c == '\0')
		return (-1);
	else if (c != '1' && c != '0')
		error_handling(WRONG_IDENTIFIER);
	else
	{
		if (!check_full_options(cub))
			error_handling(MISSING_IDENTIFIER);
		read_map(line_read, cub);
	}
	return (0);
}

void	parse_file(char **line_read, t_cub *cub)
{
	char	*l;
	int		i;
	int		aux;

	i = 0;
	l = *line_read;
	jump_spaces(*line_read, &i);
	if (*(cub->file->strmap) != '\0' && l[i] == '\0')
	{
		close_and_free_fl(line_read, cub);
		error_handling(WRONG_MAP_EMPTY);
	}
	else if (*(cub->file->strmap) != '\0')
		read_map(line_read, cub);
	else if (l[i] != '\0')
	{
		if (l[i] == 'N' || l[i] == 'S' || l[i] == 'W' || l[i] == 'E')
			aux_textures(line_read, cub, i);
		else
		{
			aux = parse_file_aux(line_read, cub, l[i], l[i + 1]);
			if (aux == -1)
				return ;
		}
	}
}
