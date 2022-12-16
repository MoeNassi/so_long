NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = so_long.c get_next_line.c get_next_line_utils.c readmapp.c swapplayer.c moveplayer.c readmap.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft.a

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean :
	rm -rf $(NAME) $(OBJ)

re : fclean all

.PHONY : re fclean clean