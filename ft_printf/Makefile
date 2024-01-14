# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 16:39:25 by albartol          #+#    #+#              #
#    Updated: 2023/11/18 16:17:04 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:=gcc
CFLAGS:=-Wall -Wextra -Werror
SRC=ft_printf.c ft_strlen.c ft_putstr_n.c ft_putnbr_n.c ft_putchar_n.c ft_putnbr_base_n.c ft_putptr_n.c
NAME=libftprintf.a
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $@ $^
	ranlib $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re