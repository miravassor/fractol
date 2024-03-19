/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_events_mngr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:54:30 by avassor           #+#    #+#             */
/*   Updated: 2022/11/25 11:03:34 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fract_ol.h"

void	switchmoves(t_init *ptr, int kc, double center_x, double center_y)
{
	if (kc == KEY_LEFT)
	{
		ptr->xmin -= center_x * MOV_VALU;
		ptr->xmax -= center_x * MOV_VALU;
	}
	else if (kc == KEY_RGHT)
	{
		ptr->xmin += center_x * MOV_VALU;
		ptr->xmax += center_x * MOV_VALU;
	}
	else if (kc == KEY_UPPP)
	{
		ptr->ymin += center_y * MOV_VALU;
		ptr->ymax += center_y * MOV_VALU;
	}
	else if (kc == KEY_DOWN)
	{
		ptr->ymin -= center_y * MOV_VALU;
		ptr->ymax -= center_y * MOV_VALU;
	}
}

int	key_event(int keycode, t_board *board)
{
	int	kc;

	kc = keycode;
	if (kc == KEY_PLUS)
		e_zoom(board, 0.5);
	else if (kc == KEY_MNUS)
		e_zoom(board, 2);
	else if (kc == KEY_RGHT || kc == KEY_LEFT || kc == KEY_UPPP
		|| kc == KEY_DOWN)
		e_move(board, kc);
	else if (kc == TILD)
		set_range(board);
	else if (kc == ESC)
		cleaner(board);
	else if (kc == TAB)
	{
		board->itr_set = board->itr_set->next;
		board->set = board->itr_set->id;
		set_range(board);
	}
	else if (kc == SHFT)
		color_shft(board);
	start_set(board);
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_board *board)
{
	int	kc;

	kc = keycode;
	if (kc == MSW_UPPP)
		e_mswup(board, x, y);
	if (kc == MSW_DOWN)
		e_mswdw(board, x, y);
	start_set(board);
	return (0);
}
