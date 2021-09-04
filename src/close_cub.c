/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 00:22:57 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 22:06:06 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	close_win(t_cub *cub)
{
	printf(":::::::::::WINDOW CLOSED!!::::::::::: \n");
	printf("___________Program finished___________\n");
	if (cub->mlx && cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	close_and_free_fm(cub);
	if (cub->ray)
		free(cub->ray);
	exit (0);
}

void	close_and_free_fl(char **line, t_cub *cub)
{
	int	fd_control;

	fd_control = cub->file->fd;
	if (cub->file)
	{
		free_file_content(cub);
		free(cub->file);
	}
	free_read_line(line, fd_control);
}

void	close_and_free_fm(t_cub *cub)
{
	if (cub->file)
	{
		free_file_content(cub);
		free(cub->file);
	}
	if (cub->fmap)
	{
		free_fmap_content(cub);
		free(cub->fmap);
	}	
}
