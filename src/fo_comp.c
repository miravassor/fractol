/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_comp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:58:44 by avassor           #+#    #+#             */
/*   Updated: 2022/11/25 11:03:28 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fract_ol.h"

void	pcolor(t_data *pimg, int x, int y, int color)
{
	pimg->addr[x * 4 + y * WIN_WDTH * 4] = color;
	pimg->addr[x * 4 + y * WIN_WDTH * 4 + 1] = color >> 8;
	pimg->addr[x * 4 + y * WIN_WDTH * 4 + 2] = color >> 16;
	pimg->addr[x * 4 + y * WIN_WDTH * 4 + 3] = color >> 24;
}

void	comp_x(t_board *board, t_init *ptr, t_data *pimg)
{
	int	i;
	int	*p;

	i = 0;
	p = board->clrsys;
	ptr->x = ptr->xmin + (ptr->xloop * ((ptr->xmax - ptr->xmin) / WIN_WDTH));
	ptr->y = ptr->ymax + (ptr->yloop * ((ptr->ymin - ptr->ymax) / WIN_HGHT));
	switchboard(board, board->set, &i);
	pcolor(pimg, ptr->xloop, ptr->yloop, p[i]);
	clear_val(ptr);
	if (++ptr->xloop < WIN_WDTH)
		comp_x(board, ptr, pimg);
}

void	comp_loop(t_board *board, t_init *ptr, t_data *pimg)
{
	ptr->xloop = 0;
	comp_x(board, ptr, pimg);
	if (++ptr->yloop < WIN_HGHT)
		comp_loop(board, ptr, pimg);
}

void	start_set(t_board *board)
{
	t_data	*pimg;
	t_init	*ptr;

	if (board->timg)
		pimg = board->timg;
	else
		pimg = board->img;
	ptr = board->init;
	data_init(ptr);
	comp_loop(board, ptr, pimg);
	mlx_put_image_to_window(board->mlx_ptr, board->win_ptr, pimg->img, 0, 0);
	if (board->timg)
	{
		free(board->img);
		board->img = board->timg;
		board->timg = NULL;
	}
}
