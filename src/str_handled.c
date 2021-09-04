/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handled.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 22:13:56 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 22:14:37 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	strtrim_handled(char **str, char const *set)
{
	char	*aux;

	aux = ft_strtrim(*str, set);
	free(*str);
	*str = aux;
	aux = NULL;
	if (*str == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	strtrim_begin_handled(char **str, char const *set)
{
	char	*aux;

	aux = ft_strtrim_begin(*str, set);
	free(*str);
	*str = aux;
	aux = NULL;
	if (*str == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	str_cutfirsts_handled(char **str, int len)
{
	char	*aux;

	aux = str_cutfirsts(*str, len);
	free(*str);
	*str = aux;
	aux = NULL;
	if (*str == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	strjoin_handled(char **line_read, char **pointed)
{
	char	*aux;

	aux = ft_strjoin(*pointed, *line_read);
	free(*pointed);
	*pointed = aux;
	aux = NULL;
	if (*pointed == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
