# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chchao <chchao@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 15:35:27 by chchao            #+#    #+#              #
#    Updated: 2021/09/24 12:32:52 by chchao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREY = \x1b[30m
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
PURPLE = \x1b[35m
CYAN = \x1b[36m

NAME 	 		= so_long

#	FILES           ############################################################
FOLDER_HEADER	= header/

FOLDER			= srcs/

PATH_OBJS		= objs/

HEADER_FILE 	= so_long.h\
				  mlx_keycode.h

SRCS    		= ft_parsing.c get_next_line.c main.c \
				  ft_define_img.c ft_get_all.c ft_print_map.c \
				  ft_print_map_exit.c  ft_print_map_flower.c \
				  ft_print_map_bee.c ft_move.c ft_game_over.c \
				  free_line.c

SRC				= $(addprefix ${FOLDER},${SRCS})

HEADERS			= $(addprefix ${FOLDER_HEADER},${HEADER_FILE})

OBJS			= ${SRC:.c=.o}

LIB				= libft.a

LIBFT			= libft/libft.a

#                   ############################################################
#	COMPILATION		############################################################
CC	     		= gcc

FLAGS    		= -Wall -Werror -Wextra

RM				= rm -rf

MLX				= minilibx/libmlx.a

LIB_MLX		 	= -I minilibx -L minilibx -lmlx -framework OpenGL -framework Appkit
 
#	   RULES	   #############################################################

all : $(MLX) $(LIB) $(NAME)

%.o	: %.c $(HEADERS)
				  @cp Libft/libft.a ./$(NAME)
				  @printf "Please wait... $@\r"
				  @echo "$(GREEN)[Compiled]:\t$(CYAN)"$<
			  	  $(CC) $(FLAGS) -c $< -o $@

$(LIB):
					@make -C Libft all

$(MLX)			:
			  	  @$(MAKE) -C minilibx/

$(NAME)	: $(OBJS) $(HEADERS)
		  @$(CC) $(FLAGS) $(LIB_MLX) $(LIBFT) $(OBJS) -o $(NAME)
		  @echo "\n$(GREEN)[OK]:\t\t$(YELLOW)Minilibx"
		  @echo "$(GREEN)[OK]:\t\t$(YELLOW)so_long"

clean :
		$(MAKE) clean -C minilibx/
		$(MAKE) clean -C Libft/
		$(RM) srcs/*.o
		@make -C ./libft clean
		@echo "$(GREEN)[CLEAN]:\t\t$(YELLOW)objs"
		@${RM} ${OBJ}

fclean : clean
		@make -C ./libft fclean
		@${RM} $(NAME)
		@printf "All clean in the folder \n"
		@rm -f $(NAME) 

re : fclean all

.PHONY : all re fclean clean