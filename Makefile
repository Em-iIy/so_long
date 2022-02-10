# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 11:28:38 by gwinnink          #+#    #+#              #
#    Updated: 2022/02/10 15:47:06 by gwinnink         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./so_long

## Files
FILES_SRCS =	main.c \
				hook_utils.c \
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
				put_frame.c

FILES_OBJS = $(FILES_SRCS:.c=.o)

## Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

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


## Creating all files
all : $(LIBFT) $(LIBFTPRINTF) $(MLX) $(NAME) 

# Compiling
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBFTPRINTF) \
		$(MLX) $(MLXFLAGS) -o $(NAME)

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

## Running
# Valid maps
run : $(NAME)
	$(NAME) ./maps/map.ber

run2 : $(NAME)
	$(NAME) ./maps/map2.ber
	
small : $(NAME)
	$(NAME) ./maps/smallmap.ber
	
large : $(NAME)
	$(NAME) ./maps/longlongmap.ber

run_all : 	run \
			run2 \
			small \
			large

# Invalid maps
invalid_c : $(NAME)
	-$(NAME) ./maps/invalid_c.ber

invalid_e : $(NAME)
	-$(NAME) ./maps/invalid_e.ber
	
invalid_p : $(NAME)
	-$(NAME) ./maps/invalid_p.ber

invalid_size : $(NAME)
	-$(NAME) ./maps/invalid_size.ber
	
invalid_walls : $(NAME)
	-$(NAME) ./maps/invalid_walls.ber
	
invalid_map_config : $(NAME)
	-$(NAME) ./maps/invalid_map_config.ber
	
invalid_map_path : $(NAME)
	-$(NAME) apple

invalid :	invalid_c \
			invalid_e \
			invalid_p \
			invalid_size \
			invalid_walls \
			invalid_map_config \
			invalid_map_path

## PHONY
.PHONY : all clean fclean re mlx_clean mlx_fclean libft_clean \
			libft_fclean fclean_all re_all