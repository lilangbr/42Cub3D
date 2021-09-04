/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_verify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 22:27:46 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/28 18:36:38 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	test_args(char **argv)
{
	int		ret;
	size_t	arglen;

	arglen = ft_strlen(argv[1]);
	if (arglen >= 4)
	{
		ret = ft_strncmp((argv[1] + arglen - 4), ".cub", 4);
		if (ret)
			error_handling(INVALID_ARG1);
	}
	else if (arglen < 4)
		error_handling(INVALID_ARG1);
}

int	verify_args(int argc, char **argv)
{
	if (argc == 1)
		error_handling(NUMBER_OF_ARGS);
	else if (argc < 3)
		test_args(argv);
	else
		error_handling(NUMBER_OF_ARGS);
	return (0);
}
