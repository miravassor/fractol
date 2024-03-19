/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_iter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:21:25 by avassor           #+#    #+#             */
/*   Updated: 2022/11/25 15:32:04 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fract_ol.h"

void	itr_mndl(t_board *board, int *i)
{
	t_init	*ptr;

	ptr = board->init;
	if ((*i == ITER))
		return ;
	ptr->trec = ptr->xrec;
	ptr->xrec = (ptr->xrec * ptr->xrec - ptr->yrec * ptr->yrec) + ptr->x;
	ptr->yrec = 2 * (ptr->trec * ptr->yrec) + ptr->y;
	if ((ptr->xrec * ptr->xrec + ptr->yrec * ptr->yrec) < 4.0)
	{
		(*i)++;
		itr_mndl(board, i);
	}
}

void	itr_tcrn(t_board *board, int *i)
{
	t_init	*ptr;

	ptr = board->init;
	if ((*i == ITER))
		return ;
	ptr->trec = ptr->xrec;
	ptr->xrec = (ptr->xrec * ptr->xrec - ptr->yrec * ptr->yrec) + ptr->x;
	ptr->yrec = (-2 * ptr->trec * ptr->yrec) + ptr->y;
	if ((ptr->xrec * ptr->xrec + ptr->yrec * ptr->yrec) < 4.0)
	{
		(*i)++;
		itr_tcrn(board, i);
	}
}

void	itr_burn(t_board *board, int *i)
{
	t_init	*ptr;

	ptr = board->init;
	if ((*i == ITER))
		return ;
	ptr->xrec = fabs(ptr->xrec);
	ptr->yrec = fabs(ptr->yrec);
	ptr->trec = ptr->xrec;
	ptr->xrec = (ptr->xrec * ptr->xrec - ptr->yrec * ptr->yrec) + ptr->x;
	ptr->yrec = (2 * (ptr->trec * ptr->yrec)) + ptr->y;
	if ((ptr->xrec * ptr->xrec + ptr->yrec * ptr->yrec) < 4.0)
	{
		(*i)++;
		itr_burn(board, i);
	}
}

void	itr_jlia(t_board *board, int *i)
{
	t_init	*ptr;

	ptr = board->init;
	if ((*i == ITER))
		return ;
	if (!ptr->xrec)
	{
		ptr->xrec = ptr->x;
		ptr->yrec = ptr->y;
	}
	if (!ptr->jx)
	{
		ptr->jx = -0.766667;
		ptr->jy = -0.090000;
	}
	ptr->trec = ptr->xrec;
	ptr->xrec = (ptr->xrec * ptr->xrec - ptr->yrec * ptr->yrec) + ptr->jx;
	ptr->yrec = (2 * ptr->trec * ptr->yrec) + ptr->jy;
	if ((ptr->xrec * ptr->xrec + ptr->yrec * ptr->yrec) < 4.0)
	{
		(*i)++;
		itr_jlia(board, i);
	}
}
