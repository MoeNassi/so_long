NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = so_long.c readmapp.c mapchecker.c get_next_line.c get_next_line_utils.c ft_error.c heiwei.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft.a

%.o : %.c so_long.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean :
	rm -rf $(NAME) $(OBJ)

re : fclean all

.PHONY : re fclean clean