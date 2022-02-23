# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 11:29:00 by gwinnink          #+#    #+#              #
#    Updated: 2022/02/23 12:48:37 by gwinnink         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_printf.c ft_putchar.c ft_puthexnum.c ft_putnbr.c ft_putptr.c ft_putstr.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
	@ar crsu $(NAME) $(OBJS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re