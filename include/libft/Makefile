# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 13:02:54 by aosset-o          #+#    #+#              #
#    Updated: 2025/07/04 12:33:01 by aosset-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Werror -Wextra

NAME = libft.a
SRC = 	ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c \
		ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c \
		ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_putchar_fd.c\
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_split.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_lstnew.c ft_lstadd_front.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		ft_lstsize.c ft_atol.c		

OBJ = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
INCLUDE = libft.h
RM = rm -f

all: $(NAME)

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
bonus:all $(BONUS_OBJS)
	@ar rcs $(NAME) $(BONUS_OBJS)
	
clean:
	@$(RM) $(OBJ) $(BONUS_OBJS)
fclean: clean
	@$(RM) $(NAME)
re: fclean all