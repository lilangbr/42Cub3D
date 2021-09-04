/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_trim_begin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:59:06 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 21:49:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	is_in(char c, char const *set)
{
	if (!(*set))
		return (0);
	else if (c == *set)
		return (1);
	else
	{
		set = set + 1;
		return (is_in(c, set));
	}
}

static int	marker(const char *s, const char *set)
{
	int			i;
	size_t		s_len;

	s_len = ft_strlen(s);
	i = 0;
	while (s_len)
	{
		if (is_in(s[i], set) && s[i] != '\0' && i > -1)
		{
			i = i + 1;
			s_len = s_len - 1;
		}
		else
			break ;
	}
	return (i);
}

char	*ft_strtrim_begin(char const *s1, char const *set)
{
	int		b;
	int		e;
	char	*s2;

	if (!s1 || !set)
		return (NULL);
	b = marker(s1, set);
	e = ft_strlen(s1);
	if (b > e)
		b = e;
	s2 = (char *)malloc((e - b + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, &s1[b], e - b + 1);
	return (s2);
}
