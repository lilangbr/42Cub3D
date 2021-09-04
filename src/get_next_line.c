/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 20:46:03 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/29 19:33:11 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*f_calloc(int size)
{
	char	*s;
	int		i;

	i = 0;
	s = malloc((size + 1) * sizeof(char));
	while (i < size)
		s[i++] = '\0';
	return (s);
}

static int	core_gnl_core(t_vars *v, char **rest, char **line)
{
	v->ret = read(v->fd, (v->buff), BUFFER_SIZE);
	while (v->ret > 0)
	{
		v->lineresult = f_creatline(&(v->buff), rest, line);
		if (v->lineresult)
			return (v->lineresult);
		v->ret = read(v->fd, (v->buff), BUFFER_SIZE);
	}		
	if (v->ret == -1)
	{
		f_strfree(line);
		return (-1);
	}
	return (0);
}

static int	gnl_core(t_vars *v, char **rest, char **line)
{
	*line = malloc(1 * sizeof(char));
	if (!(*line))
		return (-1);
	**line = '\0';
	while (**rest)
	{
		f_strcopy(&(v->buff), rest, 0, 0);
		v->lineresult = f_creatline(&(v->buff), rest, line);
		if (v->lineresult)
			return (v->lineresult);
	}
	if (core_gnl_core(v, rest, line))
	{
		if (v->lineresult)
			return (v->lineresult);
		if (v->ret == -1)
			return (-1);
	}
	v->lineresult = f_creatline(&(v->buff), rest, line);
	if (v->lineresult)
		return (v->lineresult);
	f_strfree(rest);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*residual;
	t_vars		v;

	v.buff = f_calloc(BUFFER_SIZE + 1);
	v.fd = fd;
	if (line == NULL || fd < 0 || fd >= OPEN_MAX || (read(fd, NULL, 0))
		 || BUFFER_SIZE < 1 || !v.buff)
		return (-1);
	if (!residual)
	{
		residual = f_calloc(BUFFER_SIZE + 1);
		if (!residual)
			return (-1);
	}
	v.gnl = gnl_core(&v, &residual, line);
	if (v.gnl == -1)
		f_strfree(&residual);
	f_strfree(&(v.buff));
	v.buff = NULL;
	return (v.gnl);
}
