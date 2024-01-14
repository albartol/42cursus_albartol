# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 15:18:30 by albartol          #+#    #+#              #
#    Updated: 2023/12/23 18:30:27 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:=gcc

CFLAGS:=-Wall -Wextra -Werror

SRC=push_swap_utils.c push_utils.c reverse_utils.c rotate_utils.c \
swap_utils.c push_swap_stack_utils.c ft_sort.c ft_merge_sort.c ft_sort_types.c \
ft_sort_small.c ft_sort_medium.c ft_sort_big.c

SRC_B=bonus/checker.c bonus/checker_utils.c bonus/push_utils_b.c \
bonus/swap_utils_b.c bonus/reverse_utils_b.c bonus/rotate_utils_b.c

SRC_PS=push_swap.c

NAME=push_swap

NAME_BNS=checker

OBJ=$(SRC:.c=.o)

OBJ_B=$(SRC_B:.c=.o)

OBJ_PS=$(SRC_PS:.c=.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C libft

$(NAME): $(OBJ_PS) $(OBJ)
	@$(MAKE) -C libft
	@$(CC) $(CFLAGS) $^ -L. -lft -o $@
	@echo "(•̀ᴗ•́)و ඞ… $(NAME) creado!"

clean:
	@$(MAKE) clean -C libft
	@rm -f $(OBJ) $(OBJ_PS) $(OBJ_B)
	@echo "(╯°□°）╯︵ ┻━┻ $(NAME) OBJs eliminados!"

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME) $(NAME_BNS)
	@echo "(╯°□°）╯︵ ┻━┻ $(NAME) y $(NAME_BNS) eliminados!"

re: fclean all

bonus: $(NAME_BNS)

$(NAME_BNS): $(OBJ_B) $(OBJ)
	@$(MAKE) -C libft
	@$(CC) $(CFLAGS) $^ -L. -lft -o $@
	@echo "(•̀ᴗ•́)و ඞ… $(NAME_BNS) creado!"

.PHONY: all clean fclean re bonus