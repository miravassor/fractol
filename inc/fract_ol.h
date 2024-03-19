/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:14:42 by avassor           #+#    #+#             */
/*   Updated: 2022/11/25 15:32:19 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include  "./../minilibx-linux/mlx.h"
# include "./../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

# define WIN_WDTH 700
# define WIN_HGHT 700
# define MOV_VALU 0.09
# define ZOM_VALU 1.1
# define ITER 150

# define KEY_PLUS 65451
# define KEY_MNUS 65453
# define KEY_RGHT 65363
# define KEY_LEFT 65361
# define KEY_UPPP 65362
# define KEY_DOWN 65364
# define TILD 96
# define ESC 65307
# define TAB 65289
# define SHFT 65505

# define MSW_UPPP 4
# define MSW_DOWN 5
# define QUT_WIND 17

typedef enum e_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}	t_event;

typedef enum e_set
{
	MNDL,
	JLIA,
	TCRN,
	BURN,
	RROR
}	t_set;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_init
{
	int		xloop;
	int		yloop;
	int		thresh;
	double	x;
	double	y;
	double	ymin;
	double	ymax;
	double	xmin;
	double	xmax;
	double	xrec;
	double	yrec;
	double	trec;
	double	jx;
	double	jy;
}	t_init;

typedef struct s_itr
{
	struct s_itr	*prev;
	t_set			id;
	struct s_itr	*next;
}	t_itr;

typedef struct s_clr
{
	struct s_clr	*prev;
	int				*set;
	int				size;
	struct s_clr	*next;
}	t_clr;

typedef struct s_board
{
	t_init	*init;
	t_data	*img;
	t_data	*timg;
	t_set	set;
	t_itr	*itr_set;
	t_clr	*pal;
	char	*clrmap;
	void	*mlx_ptr;
	void	*win_ptr;
	int		shades[20];
	int		clrsys[300];
	int		argc;
	char	**argv;
}	t_board;

void	clear_val(t_init *ptr);
void	clear_arr(int *clrsys);
void	data_init(t_init *ptr);
void	cleaner(t_board *board);
void	set_init(t_board *board);
void	check_arg(t_board *board);
void	set_range(t_board *board);
void	start_set(t_board *board);
void	initializr(t_board *board);
void	color_shft(t_board *board);
void	color_sets(t_board *board);
void	print_help(t_board *board);
void	init_itrset(t_board *board);
void	itr_mndl(t_board *board, int *i);
void	itr_jlia(t_board *board, int *i);
void	itr_tcrn(t_board *board, int *i);
void	itr_burn(t_board *board, int *i);
void	img_buff(t_data *img, void *mlx_ptr);
void	timg_buff(t_board *board, void *mlx_ptr);
void	pcolor(t_data *pimg, int x, int y, int color);
void	switchboard(t_board *board, t_set id, int *i);
void	add_color(t_board *board, int *set, int size);
void	frst_link(t_board *board, int *set1, int size);
void	color_systm(t_board *board, int *shades, int n);
void	board_init(t_board *board, char **argv, int argc);
void	comp_x(t_board *board, t_init *ptr, t_data *pimg);
void	comp_loop(t_board *board, t_init *ptr, t_data *pimg);
void	switchmoves(t_init *ptr, int kc, double center_x, double center_y);

int		e_close(t_board *board);
int		e_move(t_board *board, int kc);
int		skipnsign(char *ptr, int *sign);
int		line_chckr(char *argv, char *str);
int		e_zoom(t_board *board, double zoom);
int		e_mswup(t_board *board, int x, int y);
int		e_mswdw(t_board *board, int x, int y);
int		key_event(int keycode, t_board *board);
int		comp_colour(int strt, int end, double d);
int		mouse_event(int keycode, int x, int y, t_board *board);

t_set	get_set(char *argv);
t_clr	*get_last(t_clr *head);

double	atoid(char *argv);

#endif
