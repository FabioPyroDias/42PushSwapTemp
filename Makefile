# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fda-cruz <fda-cruz@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 13:40:48 by fda-cruz          #+#    #+#              #
#    Updated: 2025/12/15 15:49:32 by fda-cruz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDE = -Iinclude

SRC_DIR = src
FILES = push_swap.c push_swap_op_swap.c push_swap_op_push.c \
		push_swap_op_rotate.c push_swap_op_reverse_rotate.c
SRC = $(addprefix $(SRC_DIR)/, $(FILES))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "Removed objects and directory"

fclean: clean
	@$(RM) $(NAME)
	@echo "Removed $(NAME)"

re: fclean all