# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 11:28:38 by gwinnink          #+#    #+#              #
#    Updated: 2022/02/10 13:20:49 by gwinnink         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Files
FILES_SRCS =	main.c \
				so_long_utils.c \
				put_sprite.c \
				game.c \
				sprites.c \
				map_parse.c \
				map_parse_walls.c \
				map_parse_col.c \
				map_parse_exit.c \
				map_parse_start.c \
				error_exit.c \
				put_frame.c \

FILES_OBJS = $(FILES_SRCS:.c=.o)

## Flags
CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# CFLAGS += -fsanitize=address

MLXFLAGS = -framework OpenGL -framework AppKit

## Directories
DIR_SRCS = ./srcs/

DIR_OBJS = ./objs/

DIR_LIBFT = ./libft/

DIR_FTPRINTF = ./libft/ft_printf/

DIR_MLX = ./mlx/

vpath %.c $(DIR_SRCS)

## Sources
SRCS = $(FILES_SRCS:%=$(DIR_SRCS)%)

## Objects
OBJS = $(FILES_OBJS:%=$(DIR_OBJS)%)

## Libraries
LIBFT = $(DIR_LIBFT)libft.a

LIBFTPRINTF = $(DIR_FTPRINTF)libftprintf.a

MLX = libmlx.dylib 

NAME = main

## Creating all files
all : $(LIBFT) $(LIBFTPRINTF) $(MLX) $(NAME) 

# Compiling
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBFTPRINTF) $(MLX) $(MLXFLAGS) -o $(NAME)

# Objects
$(DIR_OBJS)%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

## Libraries
$(LIBFT) :
	make -C $(DIR_LIBFT)

$(LIBFTPRINTF) :
	make -C $(DIR_FTPRINTF)
	
$(MLX) :
	make -C $(DIR_MLX)
	@mv $(DIR_MLX)libmlx.dylib ./

## Cleaning
mlx_clean :
	make -C $(DIR_MLX) clean

mlx_fclean :
	make -C $(DIR_MLX) fclean

libft_clean :
	make -C $(DIR_LIBFT) clean

libft_fclean :
	make -C $(DIR_LIBFT) fclean
	
ftprintf_clean :
	make -C $(DIR_FTPRINTF) clean

ftprintf_fclean :
	make -C $(DIR_FTPRINTF) fclean

clean : mlx_clean libft_clean ftprintf_clean
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

fclean_all : libft_fclean ftprintf_fclean mlx_fclean fclean

## Remaking
re : fclean all

re_all : fclean_all all

## PHONY
.PHONY : all clean fclean re mlx_clean mlx_fclean libft_clean \
			libft_fclean fclean_all re_all