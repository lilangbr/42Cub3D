/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:25:46 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 20:09:17 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_read_line(char **str, int fd)
{
	int	ret;

	if (str)
	{
		free(*str);
		str = NULL;
	}
	if (fd != 0)
	{
		ret = close(fd);
		if (ret == -1)
		{
			perror("\e[31mError\e[39m");
			exit(EXIT_FAILURE);
		}
	}
}

void	free_file_content(t_cub *cub)
{
	if (cub->file->t.no)
	{
		free(cub->file->t.no);
		cub->file->t.no = NULL;
	}
	if (cub->file->t.so)
	{
		free(cub->file->t.so);
		cub->file->t.so = NULL;
	}
	if (cub->file->t.we)
	{
		free(cub->file->t.we);
		cub->file->t.we = NULL;
	}
	if (cub->file->t.ea)
	{
		free(cub->file->t.ea);
		cub->file->t.ea = NULL;
	}
	if (cub->file->strmap)
	{
		free(cub->file->strmap);
		cub->file->strmap = NULL;
	}
}

void	free_fmap_content(t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->fmap->mat)
	{
		while ((cub->fmap->mat)[i] != NULL)
		{
			free((cub->fmap->mat)[i]);
			i = i + 1;
		}	
		free((cub->fmap->mat));
		cub->fmap->mat = NULL;
	}
}
