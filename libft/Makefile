# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 11:42:34 by albartol          #+#    #+#              #
#    Updated: 2023/11/20 17:17:35 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# C=gcc
# FLAGS=-Wall -Wextra -Werror
CC:=gcc
CFLAGS:=-Wall -Wextra -Werror
SRC=ft_atoi.c ft_isalpha.c ft_isprint.c ft_memcpy.c ft_strchr.c  ft_strlcpy.c \
ft_strnstr.c ft_toupper.c ft_calloc.c ft_isascii.c ft_memchr.c ft_memmove.c \
ft_strdup.c ft_strlen.c ft_strrchr.c ft_bzero.c ft_isalnum.c ft_isdigit.c \
ft_memcmp.c ft_memset.c ft_strlcat.c ft_strncmp.c ft_tolower.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c \
ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c ft_tolower.c ft_striteri.c \
\
ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
NAME=libft.a
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $@ $^
	@ranlib $@
	@echo "(•̀ᴗ•́)و ඞ… $(NAME) creado!"

# %.o: %.c
# 	@$(C) $(FLAGS) -c $< -o $@
# 	@echo "(•̀ᴗ•́)و ඞ… $@ creado!"

clean:
	@rm -f $(OBJ)
	@echo "(╯°□°）╯︵ ┻━┻ $(OBJ) eliminados!"

fclean: clean
	@rm -f $(NAME)
	@echo "(╯°□°）╯︵ ┻━┻ $(NAME) eliminado!"

re: fclean all

.PHONY: all clean fclean re
