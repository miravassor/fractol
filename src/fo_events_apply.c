/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_events_apply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:00:23 by avassor           #+#    #+#             */
/*   Updated: 2022/11/25 11:03:31 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fract_ol.h"

int	e_mswup(t_board *board, int x, int y)
{
	t_init	*ptr;
	double	mousex;
	double	mousey;
	double	inter;

	ptr = board->init;
	inter = 1.0 / 1.5;
	timg_buff(board, board->mlx_ptr);
	mousex = ptr->xmin + ((double)x * ((ptr->xmax - ptr->xmin) / WIN_WDTH));
	mousey = ptr->ymax - ((double)y * ((ptr->ymax - ptr->ymin) / WIN_HGHT));
	ptr->xmin = mousex + ((ptr->xmin - mousex) * inter);
	ptr->xmax = mousex + ((ptr->xmax - mousex) * inter);
	ptr->ymin = mousey + ((ptr->ymin - mousey) * inter);
	ptr->ymax = mousey + ((ptr->ymax - mousey) * inter);
	return (0);
}

int	e_mswdw(t_board *board, int x, int y)
{
	(void)x;
	(void)y;
	timg_buff(board, board->mlx_ptr);
	e_zoom(board, 2);
	return (0);
}

int	e_zoom(t_board *board, double zoom)
{
	double	center_x;
	double	center_y;
	t_init	*ptr;

	ptr = board->init;
	timg_buff(board, board->mlx_ptr);
	center_x = ptr->xmin - ptr->xmax;
	center_y = ptr->ymax - ptr->ymin;
	ptr->xmax += (center_x - zoom * center_x) / 2;
	ptr->xmin = ptr->xmax + zoom * center_x;
	ptr->ymin += (center_y - zoom * center_y) / 2;
	ptr->ymax = ptr->ymin + zoom * center_y;
	return (0);
}

int	e_move(t_board *board, int kc)
{
	t_init	*ptr;

	ptr = board->init;
	timg_buff(board, board->mlx_ptr);
	switchmoves(ptr, kc, (ptr->xmax - ptr->xmin), (ptr->ymax - ptr->ymin));
	return (0);
}

int	e_close(t_board *board)
{
	if (board->img)
		mlx_destroy_image(board->mlx_ptr, board->img->img);
	mlx_destroy_window(board->mlx_ptr, board->win_ptr);
	cleaner(board);
	return (0);
}
