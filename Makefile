# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 12:28:54 by jperez            #+#    #+#              #
#    Updated: 2022/10/21 20:03:46 by jperez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap 

SRCS = main.c ft_manage_stack.c ft_manage_nodes.c ft_get_entry.c ft_check_entry.c ft_orders.c ft_multiple_orders.c push_swap.c ft_aux.c ft_assign_index.c ft_to_binary.c ft_radix.c ft_run_lists.c

OBJS = $(SRCS:.c=.o)

CC = gcc -Wall -Werror -Wextra

VAL = -g3

RM = rm -f

%.o: %.c
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $? -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

val: $(OBJS)
	$(CC) $(VAL) $? -o $(NAME)
	make clean

.PHONY: all clean bonus fclean re
