/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_color_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:55:36 by avassor           #+#    #+#             */
/*   Updated: 2022/11/25 15:10:32 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fract_ol.h"

void	color_sets(t_board *board)
{
	frst_link(board, (int [13]){0x00000000, 0x005ffbf1, 0x0046eefa, 0x0041dfff,
		0x0052cffe, 0x0069bff8, 0x0079b3f4, 0x008aa7ec, 0x009a9ae1, 0x00aa8fd8,
		0x00ba83ca, 0x00c777b9, 0x00d16ba5}, 13);
	add_color(board, (int [13]){0x00000000, 0x00ff5825, 0x00ff641d, 0x00ff7014,
		0x00ff7b08, 0x00fd8600, 0x00fc9000, 0x00f99a00, 0x00f7a400, 0x00f4ae00,
		0x00f0b800, 0x00ecc100, 0x00e8ca00}, 13);
	add_color(board, (int [13]){0x00000000, 0x001DBDE6, 0x0030B3DA, 0x0044A9CD,
		0x0057A0C1, 0x006A96B5, 0x007D8CA8, 0x0091829C, 0x00A4788F, 0x00B76E83,
		0x00CA6577, 0x00DE5B6A, 0x00F1515E}, 13);
	add_color(board, (int [13]){0x00000000, 0x00f9455d, 0x00f86936, 0x00e78d01,
		0x00c9ae00, 0x009dcb23, 0x006bd566, 0x0035da9b, 0x0000dbc6, 0x0000c9e3,
		0x0000b3fa, 0x000097fe, 0x006f73e7}, 13);
	add_color(board, (int [13]){0x00000000, 0x0093f945, 0x00b9dd00, 0x00d2c000,
		0x00e2a200, 0x00ea8300, 0x00f66a28, 0x00fb5043, 0x00f9355d, 0x00f13188,
		0x00d943b1, 0x00af5bd2, 0x006f6fe7}, 13);
	add_color(board, (int [8]){0x00289e81, 0x0051975d, 0x00728d3d, 0x008f7f27,
		0x00a96e26, 0x00bd5839, 0x00c64357, 0x00bf397b}, 8);
	add_color(board, (int [8]){0x00000000, 0x00001a24, 0x00082834, 0x001a3844,
		0x002b4855, 0x003d5966, 0x004e6b78, 0x00607d8b}, 8);
	add_color(board, (int [8]){0x001e1e20, 0x0029292b, 0x00353536, 0x00414142,
		0x004e4e4e, 0x005a5a5b, 0x00686868, 0x00757575}, 8);
	add_color(board, (int [8]){0x00FFFFFF, 0x008c8c8c, 0x00787878, 0x00656565,
		0x00525253, 0x00404041, 0x002e2e30, 0x001e1e20}, 8);
	color_systm(board, board->pal->set, board->pal->size);
}

t_clr	*get_last(t_clr *head)
{
	t_clr	*exp;

	exp = head->next;
	while (exp->next != head)
		exp = exp->next;
	return (exp);
}

void	add_color(t_board *board, int *set, int size)
{
	t_clr	*ptr;
	int		*ptr1;
	int		*ptr2;
	int		i;

	if (!board->pal->next)
		ptr = board->pal;
	else
		ptr = get_last(board->pal);
	ptr->next = (t_clr *)malloc(sizeof(t_clr));
	if (!ptr->next)
		cleaner(board);
	ptr->next->set = (int *)malloc(sizeof(int) * (size + 1));
	if (!ptr->next->set)
		cleaner(board);
	ptr1 = set;
	ptr2 = ptr->next->set;
	i = 0;
	while (i++ < (size))
		*ptr2++ = *ptr1++;
	*ptr2 = 0;
	ptr->next->size = size;
	ptr->next->next = board->pal;
}

void	frst_link(t_board *board, int *set1, int size)
{
	int		*ptr1;
	int		*ptr2;
	int		i;

	board->pal = (t_clr *)malloc(sizeof(t_clr));
	if (!board->pal)
		cleaner(board);
	board->pal->set = NULL;
	board->pal->set = (int *)malloc(sizeof(int) * (size + 1));
	if (!board->pal->set)
		cleaner(board);
	ptr1 = board->pal->set;
	ptr2 = set1;
	i = 0;
	while (i++ < (size))
		*ptr1++ = *ptr2++;
	*ptr1 = 0;
	board->pal->next = NULL;
	board->pal->size = size;
}
