/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:37:10 by avassor           #+#    #+#             */
/*   Updated: 2022/11/25 15:59:06 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fract_ol.h"

void	switchboard(t_board *board, t_set id, int *i)
{
	void	(*fptr[4])(t_board *, int *);

	fptr[MNDL] = itr_mndl;
	fptr[JLIA] = itr_jlia;
	fptr[TCRN] = itr_tcrn;
	fptr[BURN] = itr_burn;
	((*fptr[id])(board, i));
}

int	line_chckr(char *argv, char *str)
{
	char	*p1;
	char	*p2;

	p1 = argv;
	p2 = str;
	while (*p1)
	{
		if (*p2 && *p1 == *p2)
		{
			p1++;
			p2++;
		}
		else
			return (0);
	}
	if (*p1 || *p2)
		return (0);
	return (1);
}

void	wrt_sets(char set[4][13], char *list)
{
	int		i;
	int		j;

	i = 0;
	while (*list)
	{
		j = 0;
		while (*list && *list != '\n')
			set[i][j++] = *list++;
		set[i][j] = '\0';
		list++;
		i++;
	}
}

t_set	get_set(char *argv)
{
	int		i;
	char	*p;
	char	set[4][13];

	i = 0;
	p = argv;
	wrt_sets(set, "mandelbrot\njulia\ntricorn\nburn\0");
	while (i < 4)
	{
		if (line_chckr(p, set[i]))
			break ;
		i++;
	}
	if (i == 0)
		return (MNDL);
	else if (i == 1)
		return (JLIA);
	else if (i == 2)
		return (TCRN);
	else if (i == 3)
		return (BURN);
	else
		return (RROR);
}

void	print_help(t_board *board)
{
	ft_printf("FRACTOL MAN\nProgram needs a set name as first parameter\n");
	ft_printf("SETS\n");
	ft_printf("\tMandelbrot : mandelbrot\n\tJulia : julia\n");
	ft_printf("\tTricorn : tricorn\n\tBurning ship : burn\n");
	ft_printf("COMMANDS\n");
	ft_printf("\t+ : zoom in\n\t- : zoom out\n");
	ft_printf("\tkeyboard arrows : move view (left/right/up/down)\n");
	ft_printf("\tmouse wheel up : zoom on mouse pointer\n");
	ft_printf("\tmouse wheel down : zoom out (center wise)\n");
	ft_printf("\ttab : switch sets\n\tshift : shift colors\n");
	ft_printf("JULIA PARAMETERS\n");
	ft_printf("The Julia set can take 2 values to modify its shape\n");
	ft_printf("This values must lands between [-2.0;2.0]\n");
	ft_printf("Inputing no values will result in the default Julia shape\n");
	ft_printf("ex : ./fract-ol julia -2 1.5 or ./fract-ol mandelbrot\n");
	ft_printf("Please restart the program with correct parameters\n");
	cleaner(board);
}
