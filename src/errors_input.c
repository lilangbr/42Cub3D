/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:43:08 by ebresser          #+#    #+#             */
/*   Updated: 2021/09/01 13:33:07 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	error_args(int error_code)
{
	if (error_code == 400)
	{
		ft_putstr_fd("[ARGS] invalid number of ", STDOUT_FILENO);
		ft_putendl_fd("args: Must be 1 or 2!", STDOUT_FILENO);
	}
	if (error_code == 401)
	{
		ft_putstr_fd("[ARGS] ", STDOUT_FILENO);
		ft_putendl_fd("invalid extension: Must be .cub!", STDOUT_FILENO);
	}	
}

void	error_ident(int error_code)
{
	if (error_code == 500)
	{
		ft_putstr_fd("[FILE IDENT] duplicate identifier: ", STDOUT_FILENO);
		ft_putendl_fd("Must be only one identifier for each!", STDOUT_FILENO);
	}
	if (error_code == 501)
	{
		ft_putstr_fd("[FILE IDENT] wrong identifier in file: ", STDOUT_FILENO);
		ft_putendl_fd("Must be [NO, SO, WE, EA, F or C]!", STDOUT_FILENO);
	}
	if (error_code == 502)
	{
		ft_putstr_fd("[FILE IDENT] missing identifiers: ", STDOUT_FILENO);
		ft_putendl_fd("All identifiers must be filled!", STDOUT_FILENO);
	}
}

void	error_options(int error_code)
{
	if (error_code == 503)
	{
		ft_putstr_fd("[FILE OPT] invalid option: Option must ", STDOUT_FILENO);
		ft_putendl_fd("be a number(int positive)!", STDOUT_FILENO);
	}
	if (error_code == 504)
	{
		ft_putstr_fd("[FILE OPT] Must be 3 args for Floor", STDOUT_FILENO);
		ft_putendl_fd(" and Ceiling. (separated by 1 comma)!", STDOUT_FILENO);
	}
	if (error_code == 505)
	{
		ft_putstr_fd("[FILE OPT] missing options: iden", STDOUT_FILENO);
		ft_putendl_fd("tifiers must be followed by options!", STDOUT_FILENO);
	}
	if (error_code == 506)
	{
		ft_putstr_fd("[FILE OPT] wrong option: color ", STDOUT_FILENO);
		ft_putendl_fd("must be between 0 and 255!", STDOUT_FILENO);
	}
	if (error_code == 507)
		ft_putendl_fd("[FILE OPT] invalid texture path.", STDOUT_FILENO);
}

void	error_map(int error_code)
{
	if (error_code == 600)
	{
		ft_putstr_fd("[MAP] empty line in map: Must not", STDOUT_FILENO);
		ft_putendl_fd(" have empty lines in map!", STDOUT_FILENO);
	}
	if (error_code == 601)
	{
		ft_putstr_fd("[MAP] tab in map: Must not ", STDOUT_FILENO);
		ft_putendl_fd("have tab in map! (Distorcion)", STDOUT_FILENO);
	}
	if (error_code == 602)
	{
		ft_putstr_fd("[MAP] invalid char in map: Must be: ", STDOUT_FILENO);
		ft_putendl_fd("space, 1, 0, or one of: [N, S, E, W]", STDOUT_FILENO);
	}
	if (error_code == 603)
	{
		ft_putstr_fd("[MAP] invalid map: Must be closed - ", STDOUT_FILENO);
		ft_putstr_fd("with only one player: inside the map, ", STDOUT_FILENO);
		ft_putendl_fd("not at edge, neither stuck!", STDOUT_FILENO);
	}
}
