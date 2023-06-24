NAME_C = client
NAME_S = server

SRC_C = client.c utils.c
SRC_S = server.c utils.c

OBJ_C = ${SRC_C:.c=.o}
OBJ_S = ${SRC_S:.c=.o}
DEPS = ${SRC_C:.c=.d}

CC = cc
CFLAGS = -Wall -Werror -Wextra -MMD -MP
RM = rm -rf

all: $(NAME_C) $(NAME_S)

$(NAME_C): $(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ_C) -o $(NAME_C)

$(NAME_S): $(OBJ_S)
	$(CC) $(CFLAGS) $(OBJ_S) -o $(NAME_S)

clean:
	$(RM) $(OBJ_C)
	$(RM) $(OBJ_S)

fclean: clean
	$(RM) $(NAME_C)
	$(RM) $(NAME_S)

re: fclean all

.PHONY:		all clean fclean re

-include :$(DEPS)