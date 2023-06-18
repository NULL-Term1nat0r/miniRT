# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 22:55:36 by estruckm          #+#    #+#              #
#    Updated: 2023/06/18 20:00:30 by estruckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			:= miniRT
SRCS 			:= main.c \
				   init.c \
				   parsing.c \
				   interpret_scene.c \
				   free_stuff.c \
				   put_pixel.c \
				   trgb.c

VPATH			:= sources:sources/parsing:sources/utils:sources/mlx_utils
BUILDDIR		:= build

CC 				:= gcc
CCFLAG 			:= -Wall -Werror -Wextra -g

# -fsanitize=address
#-g -fprofile-instr-generate -fcoverage-mapping

MLXFLAGS 		:= -lmlx -framework OpenGL -framework AppKit
LIB 			:= ./libft

MAKE			:= make

SUCCESS_COLOR 	:= \033[32m

OBJECT 			:= $(SRCS:%.c=$(BUILDDIR)/%.o)


$(NAME) : $(OBJECT)
	$(MAKE) -C $(LIB)
	$(CC) $(CCFLAG) $(MLXFLAGS) $(OBJECT) ./libft/libft.a -o $(NAME)
	echo "$(SUCCESS_COLOR) $(NAME) - Compiled with Success"

$(BUILDDIR)/%.o:%.c $(BUILDDIR)
	$(CC) $(CCFLAG) -o $@ -c $<

$(BUILDDIR):
	@mkdir $(BUILDDIR)

.PHONY: all clean fclean re compile

clean :
	@$(MAKE) -C $(LIB) clean
	@echo "$(SUCCESS_COLOR) $(NAME) - Cleaned with Success"
	@rm -rf $(OBJECT)
	@rm -rf $(BUILDDIR)

fclean : clean
	@$(MAKE) -C $(LIB) fclean
	@rm -rf ./$(NAME)
	@echo "$(SUCCESS_COLOR) $(NAME) - FCleaned with Success"

all: $(NAME)

re : fclean all

compile:
	make re
	make clean

#Get_next_line/get_next_line_bonus.a
