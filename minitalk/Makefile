# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 15:55:43 by tlefebvr          #+#    #+#              #
#    Updated: 2022/03/08 15:27:24 by tlefebvr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SERVER = server
CLIENT = client 
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFTA = libft/libft.a
MINIH = minitalk.h

SRCS = server.c \
	   client.c

SRCO = $(SRCS:.c=.o)

all : $(SRCO) $(LIBFTA) $(SERVER) $(CLIENT)

$(LIBFTA) :
	make -C libft

$(SERVER) :
	$(CC) $(CFLAGS) server.o $(LIBFTA) -o $(SERVER)

$(CLIENT) : 
	$(CC) $(CFLAGS) client.o $(LIBFTA) -o $(CLIENT)

clean :
	make clean -C libft
	rm -f $(SRCO)

fclean :
	make fclean -C libft
	rm -f $(SRCO)
	rm -f $(SERVER)
	rm -f $(CLIENT)

re: fclean all

.PHONY: clean fclean all
