# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabio <fabio@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 13:40:48 by fda-cruz          #+#    #+#              #
#    Updated: 2025/12/28 19:34:20 by fabio            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDE = -Iinclude

SRC_DIR = src
FILES = push_swap.c push_swap_utils.c \
		push_swap_op_swap.c push_swap_op_push.c \
		push_swap_op_rotate.c push_swap_op_reverse_rotate.c \
		push_swap_parse1.c push_swap_parse2.c \
		push_swap_sorting1.c push_swap_sorting2.c \
		push_swap_normalize.c \
		push_swap_chunking1.c push_swap_chunking2.c \
		push_swap_turk_sort.c 

SRC = $(addprefix $(SRC_DIR)/, $(FILES))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

BONUS = checker

BONUS_INCLUDE = -Iinclude -Ibonus/include -I42Get_Next_Line

BONUS_SRC_CHECKER = bonus/src
BONUS_FILES_CHECKER = checker.c checker_utils.c

BONUS_SRC_PS = src
BONUS_FILES_PS = 	push_swap_op_swap.c push_swap_op_push.c \
					push_swap_op_rotate.c push_swap_op_reverse_rotate.c \
					push_swap_parse1.c push_swap_parse2.c \
					push_swap_utils.c

BONUS_SRC_GNL = 42Get_Next_Line
BONUS_FILES_GNL = get_next_line.c get_next_line_utils.c

BONUS_OBJ_DIR = bonus/obj

BONUS_OBJ_CHECKER = $(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_FILES_CHECKER:.c=.o))
BONUS_OBJ_PS = $(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_FILES_PS:.c=.o))
BONUS_OBJ_GNL = $(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_FILES_GNL:.c=.o))

BONUS_OBJ = $(BONUS_OBJ_CHECKER) $(BONUS_OBJ_PS) $(BONUS_OBJ_GNL)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@echo "Removed objects and directory"

fclean: clean
	@$(RM) $(NAME) $(BONUS)
	@echo "Removed $(NAME)"

re: fclean all

bonus : all $(BONUS)

$(BONUS) : $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_INCLUDE) -o $@ $^

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_CHECKER)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) $(BONUS_INCLUDE) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_PS)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) $(BONUS_INCLUDE) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_GNL)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) $(BONUS_INCLUDE) -c $< -o $@