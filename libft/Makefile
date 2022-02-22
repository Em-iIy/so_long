# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 11:28:19 by gwinnink          #+#    #+#              #
#    Updated: 2022/02/22 10:31:47 by gwinnink         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		./ft_atoi.c ./ft_bzero.c ./ft_calloc.c ./ft_isalnum.c \
		 	./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c ./ft_isprint.c \
			./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c \
			./ft_memset.c ./ft_strchr.c ./ft_strdup.c ./ft_strlcat.c \
			./ft_strlcpy.c ./ft_strlen.c ./ft_strncmp.c ./ft_strnstr.c \
			./ft_strrchr.c ./ft_tolower.c ./ft_toupper.c ./ft_substr.c \
			./ft_strjoin.c ./ft_strtrim.c ./ft_split.c ./ft_itoa.c \
			./ft_strmapi.c ./ft_striteri.c ./ft_putchar_fd.c ./ft_putstr_fd.c \
			./ft_putendl_fd.c ./ft_putnbr_fd.c \
			./malloc_wrap.c

GNL_SRCS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

B_SRCS =	./ft_lstnew_bonus.c ./ft_lstadd_front_bonus.c ./ft_lstsize_bonus.c \
			./ft_lstlast_bonus.c ./ft_lstadd_back_bonus.c ./ft_lstdelone_bonus.c \
			./ft_lstclear_bonus.c ./ft_lstiter_bonus.c ./ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)

GNL_OBJS = $(GNL_SRCS:.c=.o)

OBJS += $(GNL_OBJS)

B_OBJS = $(B_SRCS:.c=.o)

ifdef WITH_BONUS
OBJS += $(B_OBJS)
endif

CFLAGS = -Wall -Werror -Wextra

CC = gcc

NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar rsu $(NAME) $(OBJS)

bonus : $(OBJS)
	$(MAKE) WITH_BONUS=1

clean :
	rm -f $(OBJS) $(B_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re