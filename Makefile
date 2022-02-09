## Files
FILES_SRCS =	main.c \
				so_long_utils.c \
				copy_img.c \
				game.c \
				sprites.c \
				map_parse.c \
				map_parse_walls.c \
				map_parse_col.c \
				map_parse_exit.c \
				map_parse_start.c \
				error_exit.c \

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

DIR_MLX = ./mlx/

vpath %.c $(DIR_SRCS)

## Sources
SRCS = $(FILES_SRCS:%=$(DIR_SRCS)%)

## Objects
OBJS = $(FILES_OBJS:%=$(DIR_OBJS)%)

## Libraries
LIBFT = $(DIR_LIBFT)libft.a

MLX = libmlx.dylib 

NAME = main

## Creating all files
all : $(LIBFT) $(MLX) $(NAME) 

# Compiling
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

# Objects
$(DIR_OBJS)%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

## Libraries
$(LIBFT) :
	make -C $(DIR_LIBFT)

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

clean : mlx_clean libft_clean
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

fclean_all : libft_fclean mlx_fclean fclean

## Remaking
re : fclean all

re_all : fclean_all all

## PHONY
.PHONY : all clean fclean re mlx_clean mlx_fclean libft_clean \
			libft_fclean fclean_all re_all