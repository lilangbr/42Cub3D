/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:12:08 by ebresser          #+#    #+#             */
/*   Updated: 2021/09/01 20:10:33 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	open_file(char *path, t_cub *cub)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("\e[31mError\e[39m:\n");
		exit(EXIT_FAILURE);
	}
	cub->file->fd = fd;
	return (fd);
}

static void	read_loop(char **line_read, int fd, t_cub *cub)
{
	int		ret_gnl;

	ret_gnl = get_next_line(fd, line_read);
	while (ret_gnl > 0)
	{		
		if (ret_gnl == 1)
			parse_file(line_read, cub);
		else
			ft_putstr_fd("Fail in reading the file\n", 1);
		free(*line_read);
		*line_read = NULL;
		ret_gnl = get_next_line(fd, line_read);
	}
	if (**line_read != '\0')
		read_map(line_read, cub);
	else
	{
		close_and_free_fl(line_read, cub);
		error_handling(WRONG_MAP_EMPTY);
	}
	free(*line_read);
}

static void	close_file(char **line_read, int fd, t_cub *cub)
{
	int	flagClose;

	flagClose = close(fd);
	cub->file->fd = 0;
	if (flagClose == -1)
	{
		free(*line_read);
		*line_read = NULL;
		perror("\e[31mError\e[39m");
		exit(EXIT_FAILURE);
	}
}

void	read_file(char *path, t_cub *cub)
{
	int		fd;
	char	*line_read;

	fd = open_file(path, cub);
	read_loop(&line_read, fd, cub);
	close_file(&line_read, fd, cub);
}
