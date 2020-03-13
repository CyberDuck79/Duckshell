# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 11:52:41 by fhenrion          #+#    #+#              #
#    Updated: 2020/03/13 12:17:51 by fhenrion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = duckshell

SRC_NAME = duckshell environment arguments commands executions prompt \
redirections signals free
SRC = $(addsuffix .c,$(SRC_NAME))
SRC_PATH = ./srcs/
SRC_O = $(addsuffix .o,$(SRC_NAME))
OBJ_PATH = ./objs/
OBJS = $(addprefix $(OBJ_PATH),$(SRC_O))
INCLUDES_PATH = ./includes/
LIB = libft.a

CC = gcc
CFLAGS = -Werror -Wall -Wextra -g

.PHONY: clean fclean all re bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(INCLUDES_PATH) $^ $(LIB) -o $@
	@echo "\033[0;32m[ ✓ ] [ microshell Successfully Compiled ]\033[0m"

objs/%.o : srcs/%.c
	$(CC) -c $(CFLAGS) -I$(INCLUDES_PATH) $< -o $@

clean:
	@/bin/rm -f $(OBJS)
	@echo "\033[0;32mObjects files cleaning OK\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[0;32mexecutable cleaning OK\033[0m"

re: fclean $(NAME)
