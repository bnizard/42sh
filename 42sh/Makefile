# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/28 14:29:38 by eseveno           #+#    #+#              #
#    Updated: 2014/02/28 15:20:59 by eseveno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	42sh

CC		=	cc

FLAGS	=	-Wall -Werror -Wextra -g

SRC		=	42sh.c \
			ft_putendl.c \
			ft_putstr.c \
			ft_strtrim.c \
			ft_strncmp.c \
			ft_strlen.c

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:
			$(CC) $(FLAGS) -c $(SRC)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all
