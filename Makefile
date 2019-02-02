# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/02 18:52:24 by fel-hita          #+#    #+#              #
#    Updated: 2019/02/01 15:05:00 by fel-hita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

SRCDIR=src
HEADDIR=include

CFLAGS=-I$(HEADDIR) -Wall -Wextra -Werror

SRC=$(SRCDIR)/pipex.c\
	$(SRCDIR)/ft_strsplit.c\

OBJ=$(SRCDIR)/pipex.c\
	$(SRCDIR)/ft_strsplit.o\

NAME=pipex

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^

$(LIBDIR)/%.o:$(HEADDIR)/%.h

$(LIBDIR)/%.o:$(SRCDIR)/%.c
	$(CC) -o $@ -c $<

.PHONY: clean fclean

clean :
	rm -rf $(SRCDIR)/*.o

fclean : clean
	rm -rf $(NAME)

re: fclean all
