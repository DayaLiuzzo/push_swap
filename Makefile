# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 15:36:07 by dliuzzo           #+#    #+#              #
#    Updated: 2024/01/25 18:27:20 by dliuzzo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAG = -Wall -Wextra -Werror

INC = -I /push_swap.h

LIB = -L libft/ -lft

SRCS = ft_top_node.c \
	find.c \
	find_bis.c \
	compare.c \
	chunks.c \
	ft_atoi_swap.c \
	instr_push_swap.c \
	instr_rrotate.c \
	main.c \
	create_list.c \
	ft_split_tab.c \
	instr_rotate.c \
	liberation.c \
	ft_algo.c \
	sort.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft/
	$(CC) $(FLAG) $(OBJS) -o $(NAME) $(INC) $(LIB)

%.o : %.c
	$(CC) $(FLAG) $(INC) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

lclean : 
	make fclean -C libft/

.PHONY: all clean fclean lclean re