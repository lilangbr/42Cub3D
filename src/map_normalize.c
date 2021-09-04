/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 00:15:40 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 21:11:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	get_cols_rows(t_cub *cub)
{
	int	pos_fim;
	int	pos_maior;
	int	i;
	int	j;

	i = 0;
	pos_maior = 0;
	while ((cub->fmap->mat)[i] != NULL)
	{
		pos_fim = ft_strlen((cub->fmap->mat)[i]) - 1;
		j = pos_fim;
		while ((cub->fmap->mat)[i][j] == ' ' && j >= 0)
			j = j - 1;
		pos_fim = j;
		if (pos_fim > pos_maior)
			pos_maior = pos_fim;
		i = i + 1;
	}
	cub->fmap->cols = pos_maior + 1;
	cub->fmap->rows = i;
}

static void	substr_row(t_cub *cub, int row, size_t len)
{
	char	*aux;

	aux = ft_substr((cub->fmap->mat)[row], 0, len);
	if (aux == NULL)
	{
		close_and_free_fm(cub);
		error_handling(MALLOC_FAILED);
	}
	free((cub->fmap->mat)[row]);
	(cub->fmap->mat)[row] = aux;
	aux = NULL;
}

static void	concatspace_row(t_cub *cub, int i)
{
	char	*aux;
	int		j;

	j = 0;
	aux = (char *)malloc((cub->fmap->cols + 1) * sizeof(char));
	if (aux == NULL)
	{
		close_and_free_fm(cub);
		error_handling(MALLOC_FAILED);
	}
	while (j < (int)(ft_strlen((cub->fmap->mat)[i])))
	{
		aux[j] = (cub->fmap->mat)[i][j];
		j = j + 1;
	}
	while (j < cub->fmap->cols)
	{
		aux[j] = ' ';
		j = j + 1;
	}
	aux[j] = '\0';
	free((cub->fmap->mat)[i]);
	(cub->fmap->mat)[i] = aux;
	aux = NULL;
}

void	normalize_map(t_cub *cub)
{
	int	i;
	int	stop;

	i = 0;
	get_cols_rows(cub);
	stop = cub->fmap->rows;
	while (i < stop)
	{
		if ((int)ft_strlen((cub->fmap->mat)[i]) > cub->fmap->cols)
			substr_row(cub, i, cub->fmap->cols);
		if ((int)ft_strlen((cub->fmap->mat)[i]) < cub->fmap->cols)
			concatspace_row(cub, i);
		if ((cub->fmap->mat)[i] == NULL)
		{
			close_and_free_fm(cub);
			error_handling(MALLOC_FAILED);
		}
		i = i + 1;
	}
	i = 0;
	while ((cub->fmap->mat)[i] != NULL)
		i = i + 1;
	return ;
}
