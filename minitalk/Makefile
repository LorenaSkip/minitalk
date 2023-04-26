# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 12:24:55 by lnitu             #+#    #+#              #
#    Updated: 2023/04/26 15:06:17 by lnitu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server
NAME_C = client
NAME_FT_PF = ./libftprintf/libftprintf.a
SRCS = server.c client.c
SERVER = server.c
CLIENT = client.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(%.c)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@make -C ./libftprintf
	@$(CC) $(CFLAGS) $(NAME) $(SERVER) $(NAME_FT_PF) -o $(NAME_S)
	@$(CC) $(CFLAGS) $(NAME) $(CLIENT) $(NAME_FT_PF) -o $(NAME_C)

%.c: %.o
	@$(CC) $(CFLAGS) -o $<

clean:
	@rm -f $(OBJS)
	@make clean -C ./libftprintf
	
fclean: clean
	@rm -f $(NAME_C) $(NAME_S)
	@make fclean -C ./libftprintf
	
re: fclean all

.PHONY: all clean fclean re