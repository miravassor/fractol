/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:48:33 by avassor           #+#    #+#             */
/*   Updated: 2022/11/25 11:31:56 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/fract_ol.h"

int	skipnsign(char *ptr, int *sign)
{
	int	skp;

	skp = 0;
	while (*ptr == ' ')
	{
		++skp;
		++ptr;
	}
	if (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			*sign *= -1;
		++skp;
		++ptr;
	}
	return (skp);
}

double	atoid(char *argv)
{
	double	nbr;
	double	div;
	int		sign;
	char	*ptr;

	nbr = 0.0;
	div = 0.1;
	sign = 1;
	ptr = argv;
	ptr += skipnsign(ptr, &sign);
	while (*ptr && *ptr >= '0' && *ptr <= '9')
		nbr = (nbr * 10.0) + (*ptr++ - '0');
	if (*ptr == '.')
		ptr++;
	while (*ptr && *ptr >= '0' && *ptr <= '9')
	{
		nbr = nbr + ((*ptr++ - '0') * div);
		div *= 0.1;
	}
	if (*ptr && !(*ptr >= '0' && *ptr <= '9'))
		return (-666);
	return (nbr * sign);
}

void	unleash_pal(t_clr *x)
{
	t_clr	*hold;
	t_clr	*next;
	t_clr	*temp;

	hold = x->next;
	temp = x;
	while (hold->next != temp)
	{
		next = hold->next;
		free(hold->set);
		free(hold);
		hold = next;
	}
	free(hold->set);
	free(hold);
	free(temp->set);
	free(temp);
}

void	unleash_itr(t_itr *x)
{
	t_itr	*hold;
	t_itr	*next;
	t_itr	*temp;

	hold = x->next;
	temp = x;
	while (hold->next != temp)
	{
		next = hold->next;
		free(hold);
		hold = next;
	}
	free(hold);
	free(temp);
}

void	cleaner(t_board *board)
{
	if (!board)
		;
	else
	{
		if (board->pal)
			unleash_pal(board->pal);
		if (board->itr_set)
			unleash_itr(board->itr_set);
		if (board->timg)
			free(board->timg);
		if (board->img)
			free(board->img);
		if (board->init)
			free(board->init);
		free(board->mlx_ptr);
		free(board);
	}
	exit(0);
}
