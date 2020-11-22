# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/22 14:49:19 by aeclipso          #+#    #+#              #
#    Updated: 2020/11/22 15:23:07 by aeclipso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=./src/dll_add_first.c\
	./src/dll_add_last.c\
	./src/dll_add_n.c\
	./src/dll_get.c\
	./src/dll_get_first.c\
	./src/dll_get_last.c\
	./src/dll_get_n.c\
	./src/dll_length.c\
	./src/dll_new_node.c\
	./src/dll_peek.c\
	./src/dll_peek_first.c\
	./src/dll_peek_last.c\
	./src/dll_peek_n.c\
	./src/dll_pop.c\
	./src/dll_push.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -g -O2

NAME=dll.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): %.o: %.c
	@gcc $(FLAGS) -I ./include -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all