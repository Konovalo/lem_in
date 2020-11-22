# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/22 15:52:34 by aeclipso          #+#    #+#              #
#    Updated: 2020/11/22 16:09:49 by aeclipso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SRCD = ./src/
SRCF = *.c 

OBJD -./obj/
SRC = $(addprefix $(SRCD), $(SRCF))
OBJ = $(addprefix $(OBJD), $(OBJF))
OBJF = $(SRCF:.c=.o)
LIBS = libft/libft.a dll_lib/dll.a
HEADERS = -I ./include -I ./libft/include -I ./dll_lib/include
HDR = include/lem-in.HDR
FLAGS = -Wall -Wextra -Werror -g
CC = gcc
COMP = $(CC) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)
RECOMP = $(CC) $(INCLUDES) $(HEADERS) -c $< -o $@

all: obj $(NAME)

obj:
	mkdir -p $(OBJD)

$(NAME): libft/libft.a dll_lib/dll.a $(OBJ) $(HDR)
	$(COMP)
	@printf "Compilating lem-in done"

$(OBJD)%.o:$(SRCD)%.c $(HDR)
	$(RECOMP)

clean:
	@make clean -C libft
	@make clean -C dll_lib
	@rm -Rf $(OBJ)
	@rm -Rf obj
	@printf "Clean done\n"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft
	@make fclean -C dll_lib
	@printf "FClean done\n"

libft/libft.a:
	@make -C libft

dll_lib/dll.a
	@make -C dll_lib

re: fclean all