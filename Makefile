# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msabre <msabre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 18:00:46 by msabre            #+#    #+#              #
#    Updated: 2019/08/13 20:48:11 by msabre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBF = ./includes/libft

INCL = ./includes/fillit.h

SRCS = ./src/fillit.c ./src/fillit_valid.c ./src/fillit_new_list.c ./src/fillit_solution.c \
		./src/fillit_any_ft.c

CCFL = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C $(LIBF) re
	@$(CCFL) -L $(LIBF) -lft $(SRCS) -I $(LIBF) -I $(INCL) -o $(NAME)

clean:
	@make -C $(LIBF) clean

fclean: clean
	@make -C $(LIBF) fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
