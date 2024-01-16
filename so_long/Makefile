# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 15:10:32 by albartol          #+#    #+#              #
#    Updated: 2024/01/16 17:06:14 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:=gcc

CFLAGS:=-Wall -Wextra -Werror

SRC:=src/so_long.c

OBJ:=$(SRC:.c=.o)

OBJDIR:=src/obj

NAME:=so_long

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C lib/libft
	$(CC) $(CFLAGS) $^ -L./lib/libft -lft -o bin/$@

%.o: %.c
	$(CC) $(CFLAGS) -I include -c $< -o $@

clean:
	$(MAKE) clean -C lib/libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C lib/libft
	rm -f bin/$(NAME)

re: fclean all

.PHONY: all fclean clean re $(NAME)
.SILENT: all fclean clean re $(NAME)