# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 11:28:38 by gwinnink          #+#    #+#              #
#    Updated: 2022/03/02 11:41:49 by gwinnink         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --------------------------------------------------Colors
ESC = \033
NORMAL = $(ESC)[m\017
BOLD = $(ESC)[1m
GREEN = $(ESC)[0;92m$(BOLD)
BLUE = $(ESC)[0;94m$(BOLD)

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
# ----------------------------------------Debug
# CFLAGS += -g

# ----------------------------------------MLX
MLXFLAGS = -framework OpenGL -framework AppKit

# --------------------------------------------------Directories
DIR_SRCS = ./srcs/

DIR_OBJS = ./objs/

DIR_LIBFT = ./libft/

DIR_FTPRINTF = ./libft/ft_printf/

DIR_MLX = ./mlx/

vpath %.c $(DIR_SRCS)

# ----------------------------------------Include paths
INC = -I$(DIR_LIBFT) -I$(DIR_MLX) -I$(DIR_FTPRINTF) -I$(DIR_LIBFT)/get_next_line/


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
	@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) $(LIBFTPRINTF) \
		$(LIBMLX) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)so_long made$(NORMAL)"

# ----------------------------------------Objects
$(DIR_OBJS)%.o : %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# ----------------------------------------Create directories
$(DIR_OBJS) :
	@mkdir -p $@

# ----------------------------------------Libraries
$(LIBFT) :
	@echo "$(BLUE)Compiling libft...$(NORMAL)"
	@make -C $(DIR_LIBFT)

$(LIBFTPRINTF) :
	@echo "$(BLUE)Compiling libftprintf...$(NORMAL)"
	@make -C $(DIR_FTPRINTF)
	
$(LIBMLX) :
	@echo "$(BLUE)Compiling minilibx...$(NORMAL)"
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
	@echo "$(GREEN)maps/map.ber$(NORMAL)"
	$(NAME) ./maps/map.ber

run2 : $(NAME)
	@echo "$(GREEN)maps/map2.ber$(NORMAL)"
	$(NAME) ./maps/map2.ber
	
small : $(NAME)
	@echo "$(GREEN)maps/smallmap.ber$(NORMAL)"
	$(NAME) ./maps/smallmap.ber
	
large : $(NAME)
	@echo "$(GREEN)maps/longlongmap.ber$(NORMAL)"
	$(NAME) ./maps/longlongmap.ber

run_all : 	run \
			run2 \
			small \
			large

# ----------------------------------------Invalid maps

invalid : $(NAME)
	@echo "$(GREEN)invalid_c.ber$(NORMAL)"
	-$(NAME) ./maps/invalid_c.ber
	@echo "$(GREEN)\ninvalid_e.ber$(NORMAL)"
	-$(NAME) ./maps/invalid_e.ber
	@echo "$(GREEN)\ninvalid_p.ber$(NORMAL)"
	-$(NAME) ./maps/invalid_p.ber
	@echo "$(GREEN)\ninvalid_size.ber$(NORMAL)"
	-$(NAME) ./maps/invalid_size.ber
	@echo "$(GREEN)\ninvalid_walls.ber$(NORMAL)"
	-$(NAME) ./maps/invalid_walls.ber
	@echo "$(GREEN)\ninvalid_map_config$(NORMAL)"
	-$(NAME) ./maps/invalid_map_config.ber
	@echo "$(GREEN)\nempty.ber$(NORMAL)"
	-$(NAME) ./maps/empty.ber
	@echo "$(GREEN)\ndoes_not_exist$(NORMAL)"
	-$(NAME) ./maps/does_not_exist.ber
	@echo "$(GREEN)\ninvalid_map_name$(NORMAL)"
	-$(NAME) ./maps/invalid_map_name
	
# --------------------------------------------------PHONY
.PHONY : all clean fclean re mlx_clean mlx_fclean libft_clean \
			libft_fclean fclean_all re_all invalid run_all \
			norme