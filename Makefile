# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 20:34:57 by iksaiz-m          #+#    #+#              #
#    Updated: 2024/10/09 12:54:48 by iksaiz-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR    = libft/
LIBFT        = $(LIBFT_DIR)libft.a
MINILIBX_DIR = minilibx-linux/
MINILIBX     = $(MINILIBX_DIR)libmlx.a
HEADERS      = -I $(LIBFT_DIR)
CFLAGS       = -Wall -Wextra -Werror -O3 -g3

NAME         = fractol
RM           = rm -rf
SRC = prueba.c math.c fractal_elements.c init.c

OBJS = $(SRC:.c=.o)

all: $(MINILIBX) $(LIBFT) $(NAME)
$(NAME): $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(MINILIBX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lm -lX11 -lXext

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

clean:
	$(RM) $(OBJS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
# CC           = gcc
# LIBFT_DIR    = libft/
# LIBFT        = $(LIBFT_DIR)libft.a
# MINILIBX_DIR = minilibx-linux/
# MINILIBX     = $(MINILIBX_DIR)libmlx.a
# FRACTOL_DIR  = ./
# CFLAGS       = -Wall -Wextra -Werror -O3 -g3
# HEADERS      = -I $(FRACTOL_DIR) -I $(LIBFT_DIR)
# NAME         = fractol
# RM           = rm -rf

# CFILES = $(wildcard $(FRACTOL_DIR)/*.c) \
#          $(wildcard $(FRACTOL_DIR)/fractals/*.c)

# OFILES = $(CFILES:.c=.o)

# all: $(MINILIBX) $(LIBFT) $(NAME)

# $(NAME): $(MINILIBX) $(OFILES)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OFILES) -L$(MINILIBX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lm -lX11 -lXext

# $(LIBFT):
# 	make -C $(LIBFT_DIR)

# $(MINILIBX):
# 	make -C $(MINILIBX_DIR)

# clean:
# 	$(RM) $(OFILES)

# fclean: clean
# 	$(RM) $(NAME)

# re: fclean all