# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltran <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 13:53:50 by ltran             #+#    #+#              #
#    Updated: 2017/04/25 16:25:48 by ltran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ./sources/fillit.c \
	  ./sources/ft_create_struct.c \
	  ./sources/ft_grid.c \
	  ./sources/ft_resolve.c \
	  ./sources/ft_verif.c \
	  ./sources/ft_putstr.c \

O = ./fillit.o \
	./ft_create_struct.o \
	./ft_grid.o \
	./ft_resolve.o \
	./ft_verif.o \
	./ft_putstr.o \

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc -c $(FLAG) $(SRC)
	gcc -o $(NAME) $(O) $(FLAG)

clean:
	/bin/rm -f $(O)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
