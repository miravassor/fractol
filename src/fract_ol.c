/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:15:32 by avassor           #+#    #+#             */
/*   Updated: 2022/11/25 12:01:57 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fract_ol.h"

void	check_arg(t_board *board)
{
	int		i;

	board->set = get_set(board->argv[1]);
	if (board->set == RROR)
		print_help(board);
	i = board->set;
	while (i--)
		board->itr_set = board->itr_set->next;
	if (board->argc == 4)
	{
		board->init->jx = atoid(board->argv[2]);
		if (board->init->jx == -666)
			print_help(board);
		board->init->jy = atoid(board->argv[3]);
		if (board->init->jx == -666)
			print_help(board);
		if (board->init->jx < -2.0 || board->init->jx > 2.0
			|| board->init->jy < -2.0 || board->init->jy > 2.0)
			print_help(board);
	}
}

void	set_init(t_board *board)
{
	check_arg(board);
	initializr(board);
	img_buff(board->img, board->mlx_ptr);
	start_set(board);
}

int	main(int argc, char **argv)
{
	void		*mlx_ptr;
	t_board		*board;

	if (argc != 2 && argc != 4)
		print_help(NULL);
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	board = (t_board *)malloc(sizeof(t_board));
	if (!board)
		cleaner(board);
	board->mlx_ptr = mlx_ptr;
	board_init(board, argv, argc);
	set_init(board);
	mlx_loop(board->mlx_ptr);
	cleaner(board);
	return (0);
}
