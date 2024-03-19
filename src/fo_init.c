/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:54:23 by avassor           #+#    #+#             */
/*   Updated: 2022/11/25 11:03:38 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fract_ol.h"

void	data_init(t_init *ptr)
{
	ptr->x = 0;
	ptr->y = 0;
	ptr->xloop = 0;
	ptr->yloop = 0;
	ptr->xrec = 0;
	ptr->yrec = 0;
	ptr->trec = 0;
	ptr->thresh = ITER;
}

void	board_init(t_board *board, char **argv, int argc)
{
	board->img = (t_data *)malloc(sizeof(t_data));
	if (!board->img)
		cleaner(board);
	board->init = (t_init *)malloc(sizeof(t_init));
	if (!board->init)
		cleaner(board);
	board->init->jx = 0;
	board->init->jy = 0;
	board->itr_set = NULL;
	board->pal = NULL;
	init_itrset(board);
	board->timg = NULL;
	board->argv = argv;
	board->argc = argc;
}

void	init_itrset(t_board *board)
{
	t_itr	*ptr;
	int		i;

	i = 0;
	board->itr_set = (t_itr *)malloc(sizeof(t_itr));
	if (!board->itr_set)
		cleaner(board);
	ptr = board->itr_set;
	ptr->id = i++;
	while (i < 4)
	{
		ptr->next = (t_itr *)malloc(sizeof(t_itr));
		if (!ptr->next)
			cleaner(board);
		ptr->next->id = i++;
		ptr = ptr->next;
	}
	ptr->next = board->itr_set;
	board->itr_set->prev = ptr;
}

void	clear_val(t_init *ptr)
{
	ptr->trec = 0;
	ptr->xrec = 0;
	ptr->yrec = 0;
}

void	set_range(t_board *board)
{
	t_init	*ptr;

	ptr = board->init;
	if (board->set == MNDL || board->set == TCRN || board->set == BURN)
	{
		ptr->xmin = -2.0;
		ptr->xmax = 1.0;
		ptr->ymax = -1.5;
		ptr->ymin = ptr->ymax + (ptr->xmax - ptr->xmin) * WIN_HGHT / WIN_WDTH;
	}
	else if (board->set == JLIA)
	{
		ptr->xmin = -2.0;
		ptr->xmax = 2.0;
		ptr->ymin = -2.0;
		ptr->ymax = ptr->ymin + (ptr->xmax - ptr->xmin) * WIN_HGHT / WIN_WDTH;
	}
}
