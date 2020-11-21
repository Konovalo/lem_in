# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lronnet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/29 19:33:05 by lronnet           #+#    #+#              #
#    Updated: 2019/12/29 19:33:11 by lronnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBS = common_lib ft_gnl ft_printf

export NAME_LIB_ST = libft.a

all: compile

compile:
	$(foreach lib, $(LIBS), make -C $(lib);)
	
clean:
	$(foreach lib, $(LIBS), make -C $(lib) clean;)

fclean: clean
	rm -f $(NAME_LIB_ST)
	
re: fclean all
