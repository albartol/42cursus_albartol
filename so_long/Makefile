# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 15:10:32 by albartol          #+#    #+#              #
#    Updated: 2024/01/18 18:45:04 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

CFLAGS:=-Wall -Wextra -Werror

SRC=src/so_long.c src/ft_get_map.c src/so_long_utils.c

OBJ=$(SRC:%.c=%.o)

NAME=so_long

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C lib/libft
	mkdir -p bin
	$(CC) $(CFLAGS) $^ -Llib/libft -lft -o bin/$@

%.o: %.c
	$(CC) $(CFLAGS) -O3 -Iinclude -c $< -o $@

clean:
	$(MAKE) clean -C lib/libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C lib/libft
	rm -f bin/$(NAME)

re: fclean all

.PHONY: all fclean clean re $(NAME)
# .SILENT: all fclean clean re $(NAME)