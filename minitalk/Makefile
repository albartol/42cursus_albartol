# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 12:30:33 by albartol          #+#    #+#              #
#    Updated: 2024/01/11 16:35:31 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

CFLAGS=-Wall -Wextra -Werror

SRC_C=src/client.c

SRC_S=src/server.c

NAME_C=client

NAME_S=server

OBJ_C=$(SRC_C:.c=.o)

OBJ_S=$(SRC_S:.c=.o)

LIBFT=src/libft/libft.a

all: $(LIBFT) $(NAME_S) $(NAME_C)

$(LIBFT):
	@$(MAKE) -C src/libft

$(NAME_S): $(OBJ_S)
	@$(CC) $(CFLAGS) $^ -L./src/libft -lft -o $@
	@echo "(•̀ᴗ•́)و ඞ… $(NAME_S) creado!"

$(NAME_C): $(OBJ_C)
	@$(CC) $(CFLAGS) $^ -L./src/libft -lft -o $@
	@echo "(•̀ᴗ•́)و ඞ… $(NAME_C) creado!"

clean:
	@$(MAKE) clean -C src/libft
	@rm -f $(OBJ_C) $(OBJ_S)
	@echo "(╯°□°）╯︵ ┻━┻ $(NAME_C) & $(NAME_S) OBJs eliminados!"

fclean: clean
	@$(MAKE) fclean -C src/libft
	@rm -f $(NAME_C) $(NAME_S)
	@echo "(╯°□°）╯︵ ┻━┻ $(NAME_C) y $(NAME_S) eliminados!"

re: fclean all

.PHONY: all clean fclean re