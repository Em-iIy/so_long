# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 11:28:38 by gwinnink          #+#    #+#              #
#    Updated: 2022/02/24 13:08:03 by gwinnink         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --------------------------------------------------Name
NAME = ./so_long

# --------------------------------------------------Files
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

# --------------------------------------------------Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -framework OpenGL -framework AppKit

# --------------------------------------------------Directories
DIR_SRCS = ./srcs/

DIR_OBJS = ./objs/

DIR_LIBFT = ./libft/

DIR_FTPRINTF = ./libft/ft_printf/

DIR_MLX = ./mlx/

vpath %.c $(DIR_SRCS)

# --------------------------------------------------Sources
SRCS = $(FILES_SRCS:%=$(DIR_SRCS)%)

# --------------------------------------------------Objects
OBJS = $(FILES_OBJS:%=$(DIR_OBJS)%)

# --------------------------------------------------Libraries
LIBFT = $(DIR_LIBFT)libft.a

LIBFTPRINTF = $(DIR_FTPRINTF)libftprintf.a

LIBMLX = libmlx.dylib 

# --------------------------------------------------Creating all files
all : $(NAME)

# ----------------------------------------Compiling
$(NAME) : $(DIR_OBJS) $(OBJS) $(LIBFT) $(LIBFTPRINTF) $(LIBMLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBFTPRINTF) \
		$(LIBMLX) $(MLXFLAGS) -o $(NAME)
	@echo "so_long made"

# ----------------------------------------Objects
$(DIR_OBJS)%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# ----------------------------------------Create directories
$(DIR_OBJS) :
	@mkdir -p $@

# ----------------------------------------Libraries
$(LIBFT) :
	@echo "Compiling libft..."
	@make -C $(DIR_LIBFT)

$(LIBFTPRINTF) :
	@echo "Compiling libftprintf..."
	@make -C $(DIR_FTPRINTF)
	
$(LIBMLX) :
	@echo "Compiling minilibx..."
	@make -C $(DIR_MLX)
	@mv $(DIR_MLX)libmlx.dylib ./

# --------------------------------------------------Cleaning
mlx_clean :
	@make -C $(DIR_MLX) clean

mlx_fclean :
	@make -C $(DIR_MLX) fclean

libft_clean :
	@make -C $(DIR_LIBFT) clean

libft_fclean :
	@make -C $(DIR_LIBFT) fclean
	
ftprintf_clean :
	@make -C $(DIR_FTPRINTF) clean

ftprintf_fclean :
	@make -C $(DIR_FTPRINTF) fclean

clean : mlx_clean libft_clean ftprintf_clean
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

fclean_all : libft_fclean ftprintf_fclean mlx_fclean fclean

# --------------------------------------------------Remaking
re : fclean all

re_all : fclean_all all

# --------------------------------------------------Running
# ----------------------------------------Norminette
norme:
	norminette $(DIR_SRCS)
	norminette $(DIR_LIBFT)

# ----------------------------------------Valid maps
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

# ----------------------------------------Invalid maps
invalid_c : $(NAME)
	-$(NAME) ./maps/invalid_c.ber
	@echo "\n"

invalid_e : $(NAME)
	-$(NAME) ./maps/invalid_e.ber
	@echo "\n"
	
invalid_p : $(NAME)
	-$(NAME) ./maps/invalid_p.ber
	@echo "\n"

invalid_size : $(NAME)
	-$(NAME) ./maps/invalid_size.ber
	@echo "\n"
	
invalid_walls : $(NAME)
	-$(NAME) ./maps/invalid_walls.ber
	@echo "\n"
	
invalid_map_config : $(NAME)
	-$(NAME) ./maps/invalid_map_config.ber
	@echo "\n"
	
invalid_map_empty : $(NAME)
	-$(NAME) ./maps/empty.ber
	@echo "\n"
	
invalid_map_path : $(NAME)
	-$(NAME) apple
	@echo "\n"

invalid :	invalid_c \
			invalid_e \
			invalid_p \
			invalid_size \
			invalid_walls \
			invalid_map_config \
			invalid_map_empty \
			invalid_map_path

# --------------------------------------------------PHONY
.PHONY : all clean fclean re mlx_clean mlx_fclean libft_clean \
			libft_fclean fclean_all re_all invalid run_all