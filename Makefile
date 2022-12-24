NAME = so_long
NBONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = so_long.c readmapp.c mapchecker.c get_next_line.c get_next_line_utils.c ft_error.c heiwei.c ft_enemy.c ft_counter.c ft_spriteanim.c movements.c 
BSRC = ft_enemy.c ft_counter.c ft_spriteanim.c so_long.c readmapp.c mapchecker.c get_next_line.c get_next_line_utils.c ft_error.c heiwei.c movements.c
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft.a

%.o : %.c so_long.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

bonus : $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -lmlx -framework OpenGL -framework AppKit -o $(NBONUS) libft.a

clean :
	rm -rf $(OBJ) $(BOBJ)

fclean :
	rm -rf $(NAME) $(BOBJ)

re : fclean all

.PHONY : re fclean clean