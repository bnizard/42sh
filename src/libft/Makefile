# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmellado <dmellado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/25 20:32:04 by dmellado          #+#    #+#              #
#    Updated: 2014/03/26 19:13:47 by dmellado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
LIB	= ft
HEADDIR = ../../inc

SRC =	ft_atoi.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_itoa.c \
	ft_putchar.c \
	ft_putendl.c \
	ft_putstr.c \
	ft_space_error.c \
	ft_strchr.c \
	ft_strcpy.c \
	ft_strcmp.c \
	ft_strjoin.c \
	ft_strlen.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strsplit.c \
	ft_strtrim.c

OBJ = $(subst .c,.o,$(SRC))

CC = gcc
CCFLAGS = -Werror -Wall -Wextra -Wuninitialized -g3 -O3

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	$(CC) $(CCFLAGS) -I $(HEADDIR) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: all
