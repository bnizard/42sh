# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmellado <dmellado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/25 20:34:27 by dmellado          #+#    #+#              #
#    Updated: 2014/03/27 19:36:18 by cbarbisa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 42sh
LIBNAME		= ./src/lib42sh.a
LIBFT		= ./src/libft/libft.a

SRCDIR		= ./src/
HEADDIR		= ./inc/

SRC			=	./src/arg.c \
				./src/free.c \
				./src/ft_cd.c \
				./src/ft_check1.c \
				./src/ft_check2.c \
				./src/ft_check_lexem.c \
				./src/ft_data.c \
				./src/ft_echo.c \
				./src/ft_echo_check_char.c \
				./src/ft_echo_convert.c \
				./src/ft_env.c \
				./src/ft_env1.c \
				./src/ft_env2.c \
				./src/ft_env3.c \
				./src/ft_env_errors.c \
				./src/ft_error.c \
				./src/ft_set_all.c \
				./src/ft_set_tab.c \
				./src/ft_set_type.c \
				./src/ft_setenv.c \
				./src/ft_unsetenv.c \
				./src/minishell.c \
				./src/parser.c \
				./src/path.c \
				./src/sh1.c \
				./src/sh2.c \
				./src/tree.c \
				./src/tree1.c \
				./src/tree2.c \
				./src/tree3.c

OBJ			= $(subst .c,.o,$(SRC))

CC			= gcc
CCFLAGS		= -Werror -Wall -Wextra -Wuninitialized -g3 -O3
LIBFLAG		= -L./src/ -l42sh -L./src/libft -lft
#SYSFLAG		= -ltermcap
HEADFLAG	= -I$(HEADDIR)

.PHONY: all clean fclean re $(LIBFT)

all: $(LIBFT) $(LIBNAME) $(NAME)

$(NAME): $(LIBNAME) ftsh.c
	$(CC) $(CCFLAGS) $(HEADFLAG) $(LIBFLAG) -o $(NAME) ftsh.c

$(LIBNAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

$(LIBFT):
	make -C ./src/libft

%.o: %.c
	$(CC) $(CCFLAGS) $(HEADFLAG) -o $@ -c $<

clean:
	make -C ./src/libft clean
	rm -f $(OBJ)
	rm -rf $(NAME).dSYM

fclean: clean
	make -C ./src/libft fclean
	rm -f $(LIBNAME)
	rm -f $(NAME)

re: fclean all
