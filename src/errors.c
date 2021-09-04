/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:07:21 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 19:43:44 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	error_handling(int error_code)
{
	ft_putendl_fd("\e[31mError\e[39m", STDOUT_FILENO);
	if (error_code >= 100 && error_code < 200)
		error_sys (error_code);
	if (error_code >= 400 && error_code < 500)
		error_args (error_code);
	if (error_code >= 500 && error_code < 503)
		error_ident (error_code);
	if (error_code >= 503 && error_code < 600)
		error_options (error_code);
	if (error_code >= 600 && error_code < 700)
		error_map (error_code);
	if (error_code >= 700 && error_code < 800)
		error_mlx (error_code);
	exit(error_code);
}
