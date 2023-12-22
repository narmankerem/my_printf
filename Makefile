# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knarman <knarman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 08:18:14 by knarman           #+#    #+#              #
#    Updated: 2023/12/22 16:52:36 by knarman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f

SRC = ft_printf.c ft_printf_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):	
	$(CC) $(CFLAGS) -c $(SRC) 	
	ar rc $(NAME) $(OBJ)


	
c: clean
clean: 
	$(RM) $(OBJ)
f: fclean
fclean: clean 
	$(RM) $(NAME)
re: fclean all
r: re
