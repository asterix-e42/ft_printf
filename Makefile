# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 16:51:40 by tdumouli          #+#    #+#              #
#    Updated: 2017/01/06 08:00:35 by tdumouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SPEUDO = "tdumouli"
NAME = libftprintf.a
OBJDIR = ./objet
SRCDIR = ./src
INCDIR = ./include
SRCS =	memset.o bzero.o memcpy.o memccpy.o memmove.o memchr.o memcmp.o \
		strlen.o strdup.o strcpy.o strncpy.o strcat.o strncat.o strlcat.o \
		strchr.o strrchr.o strstr.o strnstr.o strcmp.o strncmp.o atoi.o \
		isalpha.o isdigit.o isalnum.o isascii.o isprint.o toupper.o tolower.o \
		memalloc.o memdel.o strnew.o strdel.o strclr.o striter.o striteri.o \
		strmap.o strmapi.o strequ.o strnequ.o strsub.o strjoin.o strtrim.o \
		strsplit.o itoa.o putchar.o putstr.o putendl.o putnbr.o putchar_fd.o \
		putstr_fd.o putendl_fd.o putnbr_fd.o isspace.o intlen.o power.o \
		atoibase.o unsignedintlen.o erreur.o itoabaseint.o

LST =	lstadd.o lstnew.o lstdel.o lstdelone.o lstiter.o lstmap.o lstfind.o \
		lstaddend.o	lstfindsize.o lstothernew.o 

PRINT =	ft_printf.o unicorn.o

OBJ=	$(addprefix $(OBJDIR)/libc/ft_, $(SRCS)) \
		$(addprefix $(OBJDIR)/liste/ft_, $(LST)) \
		$(addprefix $(OBJDIR)/printf/, $(PRINT))

############################## normaly no change ###############################

NO_COLOR="\x1b[39m"
RED="\x1b[31m"
GREEN="\x1b[32m"
YELLOW="\x1b[33m"
CC = gcc
CFLAGS = -I$(INCDIR) -Wall -Werror -Wextra
MAKE = /usr/bin/make

ifneq ($(NAME), )
all: $(NAME)
	@echo $(GREEN)"compilation reussi"$(NO_COLOR)
else
all: $(OBJ)
	@echo $(GREEN)"compilation reussi"$(NO_COLOR)
endif

$(OBJDIR):
	@mkdir $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo $(GREEN)"objets compile"$(NO_COLOR)

$(NAME): $(OBJ)
	@ar r $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GREEN)"library compile"$(NO_COLOR)

$(NAME)2: $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	@echo $(GREEN)$(NAME)" a ete cree"$(NO_COLOR)

clean:
	@rm -rf $(OBJ)
	@$(MAKE) cleanv

ifeq ($(shell find . -type f | grep "\.o"), )
cleanv:
	@echo $(GREEN)"les objets sont clean"$(NO_COLOR)
else
cleanv:
	@echo $(RED)"il ya probleme"
	@echo $(YELLOW)$(shell echo | find . -typr f | grep "\.o" | cat -e)
	make -d
endif

cl:
	@if [ "test" = "test" ]; then\
		echo "Hello world";\
		fi

auteur:
	@echo $(SPEUDO) > auteur
	@echo $(GREEN)"le fichier auteur a bien ete cree"$(NO_COLOR)

fclean: clean
	@rm -f $(NAME)
	@echo $(GREEN)"tout est clean"$(NO_COLOR)

re: fclean all

.PHONY: all clean fclean re cleanv anc
