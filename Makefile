# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 20:27:24 by tmarts            #+#    #+#              #
#    Updated: 2022/11/27 23:03:22 by tmarts           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCE = ft_printf.c\
ft_printf_utilis.c\
ft_printf_utilis_2.c\
libft_functions.c

OBJECT = $(SOURCE:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECT)
	make -C libft
	mv libft/libft.a libftprintf.a
	ar -rcs $(NAME) $(OBJECT)

$(OBJECT): $(SOURCE) 
	$(CC) -c $(CFLAGS) $(SOURCE)

clean:
	make -C libft fclean
	rm -f $(OBJECT)	

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re