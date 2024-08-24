# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alama <alama@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 19:05:27 by alama             #+#    #+#              #
#    Updated: 2024/08/20 16:58:47 by alama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror 
 
SRC = src/main.c src/ft_create_node.c src/instruct/ft_swap.c \
      src/instruct/ft_rotate.c src/ft_free.c \
      src/instruct/ft_reverse_rotate.c \
      src/instruct/ft_push.c \
      src/instruct/ft_d_rotate.c \
      src/instruct/ft_d_r_rotate.c src/instruct/ft_d_swap.c \
	  src/start.c src/ft_print_instruct.c src/ft_count_nb.c \
	  src/ft_sort.c src/ft_more_sort.c src/ft_friend.c \
	  src/ft_error.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

PRINTF = ./printf/libftprintf.a

LIBFT = ./libft/libft.a

SRC_DIR = src

OBJ_DIR = .cache

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./printf
	@make -C ./libft 1>/dev/null
	@$(CC) $(CFLAGS) -o $(NAME) $(PRINTF) $(LIBFT) $(TOOLS) $(LINK) $(SRC) -I./includes -I./printf -I./libft
	@echo "Compilation successful!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I./includes -I./printf -I./libft

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p ./.cache/instruct

clean:
	@make clean -C ./printf 1>/dev/null
	@make clean -C ./libft 1>/dev/null
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C ./printf
	@make fclean -C ./libft 1>/dev/null
	@rm -f $(NAME) *.o
	@rm -rf *dSYM*

re: fclean $(NAME)

.PHONY: all fclean clean re printf
