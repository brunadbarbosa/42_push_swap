# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/15 19:14:35 by brmaria-          #+#    #+#              #
#    Updated: 2025/07/04 17:36:47 by brmaria-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name
NAME = push_swap

# compiler and flags:
CC = cc
CFLAGS = -Wall -Wextra -Werror

# basic and additional files:
SRC =	0-main.c\
		0.5-split.c\
		1-fill.c\
		2-swap.c\
		3-rotate.c\
		4-reverse_rotate.c\
		5-push.c\
		6-indexation.c\
		7-sorting.c\
		7.5-sort_tiny.c\
		7.75-sort_tiny_5.c\
		8-error.c
		
OBJ = $(SRC:.c=.o)

RM = rm -rf

# standard rule:
all: $(NAME)

# compile and create the lib:
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Let's build this Push Swap! Done!"

# compile .o:
%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<..."
	
# clean files:
clean:
	@$(RM) $(OBJ)
	@echo "Off with these files!"

# clean everything, .o and libft.a:
fclean: clean
	@$(RM) $(NAME)
	@echo "Binary gone!"

# recompile all:
re: fclean all

.PHONY: all re clean fclean
