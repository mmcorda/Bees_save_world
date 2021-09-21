# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chchao <chchao@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 15:35:27 by chchao            #+#    #+#              #
#    Updated: 2021/09/21 19:57:22 by chchao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	 		= so_long

#	FILES           ############################################################
FOLDER_HEADER	= header/

FOLDER			= srcs/

HEADER_FILE 	= so_long.h

SRCS    		= ft_parsing.c get_next_line.c main.c \
				  ft_define_img.c ft_get_all.c ft_my_mlx_pixel_put.c \
				  ft_game_over.c

SRC				= $(addprefix ${FOLDER},${SRCS})

HEADERS			= $(addprefix ${FOLDER_HEADER},${HEADER_FILE})

OBJS			= ${SRC:.c=.o}

#                   ############################################################
#	COMPILATION		############################################################
CC	     		= gcc

FLAGS    		= -Wall -Werror -Wextra

RM				= rm -rf

UNAME_S			= $(shell uname -s)

ifeq ($(UNAME_S),Linux)
		LIBS 	= -L ./libft -lft -lmlx -lXext -lX11
endif
ifeq ($(UNAME_S),Darwin)
		LIBS 	= -L ./libft -lft -lmlx -framework OpenGL -framework AppKit -lz
endif

COMPIL			= $(CC) $(FLAGS) ${OBJS} $(LIBS) -o $(NAME)

#	   RULES	   #############################################################
$(NAME) : $(OBJS)
		@make -C ./libft
		@$(COMPIL)
		
all : $(NAME)	

%.o : %.c
		@$(CC) $(FLAGS) -c $< -o $@
		@printf "making so_long objects... %-33.33s\r" $@
		@$(CC) -c $(FLAGS) -o $@ $<
clean :
		@make -C ./libft clean
		@${RM} ${OBJ}
		@printf "Object .o files have been deleted.\n"
		@rm -f *.o

fclean : clean
		@make -C ./libft fclean
		@${RM} $(NAME)
		@printf "All clean in the folder \n"
		@rm -f $(NAME) 

re : fclean all

.PHONY : all re fclean clean