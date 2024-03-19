/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_mnlib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:15:49 by avassor           #+#    #+#             */
/*   Updated: 2022/11/25 11:03:44 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fract_ol.h"

void	img_buff(t_data *img, void *mlx_ptr)
{
	img->img = mlx_new_image(mlx_ptr, WIN_WDTH, WIN_HGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	timg_buff(t_board *board, void *mlx_ptr)
{
	board->timg = (t_data *)malloc(sizeof(t_data));
	if (!board->timg)
		cleaner(board);
	board->timg->img = mlx_new_image(mlx_ptr, WIN_WDTH, WIN_HGHT);
	board->timg->addr = mlx_get_data_addr(board->timg->img,
			&board->timg->bits_per_pixel,
			&board->timg->line_length, &board->timg->endian);
}

void	initializr(t_board *board)
{
	board->win_ptr = mlx_new_window(board->mlx_ptr, WIN_WDTH, WIN_HGHT,
			"Fract-ol Renderer");
	if (!board->win_ptr)
		cleaner(board);
	color_sets(board);
	set_range(board);
	mlx_hook(board->win_ptr, QUT_WIND, 0, e_close, board);
	mlx_key_hook(board->win_ptr, key_event, board);
	mlx_mouse_hook(board->win_ptr, mouse_event, board);
}
