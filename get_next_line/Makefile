CC:=gcc
CFLAGS:=-Wall -Wextra -Werror
SRC=get_next_line.c get_next_line_utils.c main.c
NAME=gnl.a
BUFF=-D BUFFER_SIZE=42 
OBJ=$(SRC:.c=.o)
#parte bonus
SRCBNS=
OBJBNS=$(SRCBNS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $@ $^

buff: $(OBJ)
	$(CC) $(CFLAGS) $(BUFF) $@ $^

clean:
	@rm -f $(OBJ) $(OBJBNS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

#Hace relink: (touch bonus)

bonus: $(OBJ) $(OBJBNS)
	$(CC) $(CFLAGS) $(NAME) $^

.PHONY: all clean fclean re