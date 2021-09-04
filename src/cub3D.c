/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:12:37 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 17:29:36 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	verify_args(argc, argv);
	init_cub(&cub);
	file_in_heap(&cub);
	init_cub_file(&cub);
	read_file(argv[1], &cub);
	check_map(&cub);
	normalize_map(&cub);
	validate_map(&cub);
	fill_fmap(&cub);
	play(&cub);
	return (0);
}
