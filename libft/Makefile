# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chchao <chchao@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/02 08:52:39 by chchao            #+#    #+#              #
#    Updated: 2021/08/20 13:13:40 by chchao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
	  ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
      ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	  ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
	  ft_strchr.c ft_strncmp.c ft_strdup.c ft_strjoin.c \
	  ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strnstr.c \
	  ft_strmapi.c ft_strrchr.c ft_strtrim.c ft_substr.c \
	  ft_tolower.c ft_toupper.c 
	  
OBJ = $(SRC:.c=.o)

$(NAME): 	$(OBJ)
			ar rc $(NAME) $(OBJ)

all:		$(NAME)

clean:
			rm -rf $(OBJ)

fclean: 	clean
			rm -rf $(NAME)

re: 		fclean all

.PHONY : all fclean clean re
