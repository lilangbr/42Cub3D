/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 20:46:03 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 21:58:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 20
# endif

typedef struct s_get_next_line
{
	char		*buff;	
	ssize_t		ret;
	int			lineresult;
	int			fd;
	int			gnl;
}				t_vars;

size_t	ft_strlen(const char *s);
void	f_strfree(char **s);
void	f_strcopy(char **dst, char **src, int start_src, int start_dst);
int		f_strjoin(char **dst_line, char **add_buff);
int		f_creatline(char **buf, char **rest, char **line);
int		get_next_line(int fd, char **line);

#endif
