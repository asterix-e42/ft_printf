# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 20:56:09 by tdumouli          #+#    #+#              #
#    Updated: 2016/12/15 06:15:16 by tdumouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -I. -Wall -Wextra

LIB = libft

SRC = ft_printf.c unicorn.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@ar r $(NAME) $(OBJ) $(LIB)/*.o
	@ranlib $(NAME)

clean: 
	make -C libft clean
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
