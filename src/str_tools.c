/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 17:27:07 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 21:47:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	jump_spaces(char *str, int *p)
{
	while (str[*p] == ' ' || str[*p] == '\t')
		*p = *p + 1;
}

int	linemap_insert_star(char **pointed)
{
	int		ret;
	char	*star;

	star = "*";
	ret = strjoin_handled(&star, pointed);
	if (ret == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}
