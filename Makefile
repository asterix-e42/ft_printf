# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 20:56:09 by tdumouli          #+#    #+#              #
#    Updated: 2016/12/12 02:52:18 by tdumouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
CC = gcc
CFLAGS = -I. -Wall -Werror -Wextra

LIB = libft/libft.a

SRC = ft_printf.c unicorn.c maintest.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

$(LIB): $(LIB)
	make -C libft

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

ffclean: fclean
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
