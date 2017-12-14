# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 08:41:35 by ndubouil          #+#    #+#              #
#    Updated: 2017/12/14 08:44:38 by ndubouil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binaries and Flags
CC		=	/usr/bin/gcc
RM		=	/bin/rm
CFLAGS	=	-Wall -Wextra -Werror
# Directories
LIB		=	./libft/
HEADER	=	.
# GNL Files
HFILES	=	$(HEADER)/get_next_line.h
MAIN	=	main.c
SRC		=	get_next_line.c
OBJ		=	$(patsubst %.c,%.o,$(SRC))
# Name
NAME	=	gnl

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):	$(OBJ) $(MAIN) $(HFILES) $(LIB) Makefile
		@echo "Compiling libft ..."
		@make -C $(LIB)
		@echo "Building $(NAME) ..."
		@$(CC) $(CFLAGS) $(MAIN) $(OBJ) -I$(HEADER) -I$(LIB) -L$(LIB) -lft -o $(NAME)
		@echo "OK"

%.o: 		%.c
		@echo "Creating $@ ..."
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@echo "Cleaning Objs ..."
		@$(RM) -f $(OBJ)
		@echo "Cleaning libft Objs ..."
		@make clean -C $(LIB)

fclean:		clean
		@echo "Cleaning $(NAME) exec"
		@$(RM) -f $(NAME)
		@echo "Cleaning libft exec"
		@make fclean -C $(LIB)

re:			fclean all
