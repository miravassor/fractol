# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avassor <avassor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 10:40:46 by avassor           #+#    #+#              #
#    Updated: 2022/11/25 15:57:14 by avassor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRACTOL	= fractol
NAME	= $(FRACTOL)

CC		=	gcc
CFLAGS 	=	-g -Wall -Wextra -Werror
LFLAGS	=	-lX11 -lXext -lm
INC		=	-I ./inc/

MLX_PATH	=	minilibx-linux/
MLX_NAME	=	libmlx_Linux.a
MINILIBX	=	$(MLX_PATH)$(MLX_NAME)

PRINTF_PATH	 =	ft_printf/
PRINTF_NAME	 =	libftprintf.a
PRINTF		 =	$(PRINTF_PATH)$(PRINTF_NAME)

SRC_PATH =	src/
OBJ_PATH =	obj/

SRC =				fract_ol.c			\
					fo_init.c			\
					fo_mnlib.c			\
					fo_iter.c			\
					fo_utils_1.c		\
					fo_utils_2.c		\
					fo_events_mngr.c	\
					fo_events_apply.c	\
					fo_color_1.c 		\
					fo_color_2.c		\
					fo_comp.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJS = ${SRCS:${SRC_PATH}%.c=${OBJ_PATH}%.o}

$(NAME): $(MINILIBX) $(PRINTF) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(MINILIBX) $(PRINTF) $(LFLAGS)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c ./inc/fract_ol.h
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(MINILIBX):
	$(MAKE) -sC $(MLX_PATH)

$(PRINTF):
	$(MAKE) -sC $(PRINTF_PATH)

all: $(NAME)

clean:
	rm -rdf $(OBJ_PATH)
	$(MAKE) clean -C $(MLX_PATH)
	$(MAKE) clean -C $(PRINTF_PATH)

fclean: clean
	rm -f $(NAME)
	rm -f $(PRINTF_PATH)$(PRINTF_NAME)
	rm -f $(MLX_PATH)$(MLX_NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re
