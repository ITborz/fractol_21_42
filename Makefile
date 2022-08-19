# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 17:16:58 by bkristen          #+#    #+#              #
#    Updated: 2022/06/05 15:48:58 by iugolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

MINILIBX = $(MINILIBX_DIR)libmlx.a

MINILIBX_DIR = ./mlx/

MINILIBX_HEADER = $(MINILIBX_DIR)

HEADER	=	$(INCLUDES_PATH)fractal.h

INCLUDES_PATH = ./src/

SRC_DIR = ./src/

SRC_FILES	= key_hook.c fr_mandelbrot.c color.c exit.c \
			fr_julia.c utils1.c main.c key_hook_julia.c fr_burning_ship.c \
			key_hook_bs.c x_close_utils.c

SRCS	=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ		=	${SRCS:.c=.o}

CC		=	cc

CFLAGS  =  -O3 -Wall -Wextra -Werror -Imlx 


.PHONY	:	all clean fclean re 

all: $(NAME) 

$(NAME): $(MINILIBX) $(OBJ)
	$(CC)  $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(MINILIBX):
	make -C $(MINILIBX_DIR)
	

# на что влиеят -.с как правильно записать?
%.o: %.c $(HEADER) Makefile 
	$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
