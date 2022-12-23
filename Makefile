NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = so_long.c readmapp.c mapchecker.c get_next_line.c get_next_line_utils.c ft_error.c heiwei.c
BSRC = enemy.c
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft.a

%.o : %.c so_long.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

bonus : $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft.a

clean :
	rm -rf $(OBJ)

fclean :
	rm -rf $(NAME) $(OBJ) $(BOBJ)

re : fclean all

.PHONY : re fclean clean