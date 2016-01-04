#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/23 10:38:37 by shamdani          #+#    #+#              #
#    Updated: 2015/03/23 14:29:02 by shamdani         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap

CC = gcc -Wall -Werror -Wextra

SRC =	./src/push_swap4.c\
		./src/push_swap2.c\
		./src/push_swap3.c\
		./src/push_swap.c


COMPILE = echo "\033[36mCompile --push_swap-- ...."
COMPILED = echo "\033[32mCompiled --push_swap-- Successfully"
CLEAN = echo "\033[36mClean --push_swap-- ...."
CLEANED = echo "\033[32mCleaned --push_swap-- Successfully"

all: $(NAME)

$(NAME):
	@$(COMPILE)
	@make -C ./libft re
	@$(CC) $(SRC) -o $(NAME) ./libft/libft.a
	@$(COMPILED)

norme:
	@norminette $(SRC) ./src/push_swap.h

clean:
	@$(CLEAN)
	@rm -f $(SRC_OBJ)
	@$(CLEANED)

fclean: clean
	@rm -f $(NAME)

re : fclean all