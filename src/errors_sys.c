/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_sys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:40:36 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 19:42:41 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	error_sys(int error_code)
{
	if (error_code == 100)
	{
		ft_putstr_fd("[SYSTEM] Malloc failed", STDOUT_FILENO);
		ft_putendl_fd(" when manipulating string!", STDOUT_FILENO);
	}
	if (error_code == 101)
	{
		ft_putstr_fd("[SYSTEM] Malloc failed", STDOUT_FILENO);
		ft_putendl_fd(" when allocating struct!", STDOUT_FILENO);
	}
}

void	error_mlx(int error_code)
{
	if (error_code == 700)
		ft_putendl_fd("[MLX] init minilibx: connection failed", STDOUT_FILENO);
}
