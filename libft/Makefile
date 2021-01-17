# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izouiten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 13:55:53 by izouiten          #+#    #+#              #
#    Updated: 2019/04/04 14:30:26 by izouiten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

Obj = *.o

CFLAG = -Wall -Wextra -Wall

HEADER = includes

all: $(NAME)

$(NAME):
	@gcc -g $(FLAG) -c $(SRC) -I$(HEADER) && ar rc $(NAME) $(Obj)

clean:
	@/bin/rm -f $(Obj)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(Obj)

re: fclean all

