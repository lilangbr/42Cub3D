/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cutfirsts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:59:06 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 21:39:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*str_cutfirsts(char const *s1, int len)
{
	int		b;
	int		e;
	char	*s2;

	if (!s1)
		return (NULL);
	b = len;
	e = ft_strlen(s1);
	if (b > e)
		b = e;
	s2 = (char *)malloc((e - b + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, &s1[b], e - b + 1);
	return (s2);
}
