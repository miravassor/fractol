/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_color_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:49:26 by avassor           #+#    #+#             */
/*   Updated: 2022/11/25 14:17:24 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fract_ol.h"

void	color_shft(t_board *board)
{
	board->pal = board->pal->next;
	color_systm(board, board->pal->set, board->pal->size);
}

int	comp_colour(int strt, int end, double d)
{
	int	str_rgb[3];
	int	end_rgb[3];

	str_rgb[0] = ((strt >> 16) & 0xFF);
	str_rgb[1] = ((strt >> 8) & 0xFF);
	str_rgb[2] = ((strt >> 0) & 0xFF);
	end_rgb[0] = ((end >> 16) & 0xFF);
	end_rgb[1] = ((end >> 8) & 0xFF);
	end_rgb[2] = ((end >> 0) & 0xFF);
	str_rgb[0] = (end_rgb[0] - str_rgb[0]) * d + str_rgb[0];
	str_rgb[1] = (end_rgb[1] - str_rgb[1]) * d + str_rgb[1];
	str_rgb[2] = (end_rgb[2] - str_rgb[2]) * d + str_rgb[2];
	return (0xFF << 24 | str_rgb[0] << 16 | str_rgb[1] << 8 | str_rgb[2]);
}

void	color_systm(t_board *board, int *shades, int n)
{
	int		*p;
	int		i;
	int		j;
	int		x;
	double	d;

	p = board->clrsys;
	i = 0;
	x = 0;
	clear_arr(board->clrsys);
	while (i < ITER)
	{
		j = 0;
		while ((i + j) < ITER && j < (ITER / (n - 1)))
		{
			d = (double)j / (ITER / (n - 1));
			p[i + j] = comp_colour(shades[x], shades[x + 1], d);
			j++;
		}
		x++;
		i += j;
	}
	p[ITER - 1] = 0;
}

void	clear_arr(int *clrsys)
{
	int	*ptr;

	ptr = clrsys;
	while (ptr - clrsys < ITER)
	{
		*ptr++ = 0;
	}
	*ptr = 0;
}
