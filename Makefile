# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 18:26:35 by tfedoren          #+#    #+#              #
#    Updated: 2022/07/25 14:53:18 by tfedoren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT_PATH	=	Libft

SRC =	draw.c \
		main.c \
		read_file.c \
		rotate_flatten.c \
		utils.c \
		default.c \
		deal_key.c \
		color_management.c \
		isometric_helpers.c


OBJ = $(SRC:.c=.o)

MINILIBX = minilibx_macos/libmlx.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	make -C minilibx_macos
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_PATH) $(MINILIBX) -lft -framework OpenGL -framework AppKit -o $(NAME)
#	ar rcs $(NAME) $(OBJ)

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all
	make -C $(LIBFT_PATH) re

.PHONY: all clean fclean re bonus

#gcc main.c -Lmlx -lmlx -framework OpenGL -framework AppKit