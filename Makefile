# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/09 17:15:33 by aosset-o          #+#    #+#              #
#    Updated: 2025/07/28 18:50:09 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

CC=cc
CFLAGS=-Wall -Werror -Wextra

LIBFT_PATH = include/libft

LIBFT = $(LIBFT_PATH)/libft.a

NAME = pipex
SRC = main.c utils.c
OBJ = $(SRC:.c=.o)

INCLUDE = push_swap.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) 
	@echo "$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"
%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIBFT_PATH) -c $< -o $@
	@echo "$(NAME): $(GREEN)$(OBJ) was created$(RESET)"
$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)
	@echo "$(NAME): $(GREEN)$(LIBFT) was created$(RESET)"
clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@rm -f $(OBJ)
	@echo "$(NAME): $(RED)$(OBJ) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"
fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
re: fclean all

.PHONY: all clean fclean re