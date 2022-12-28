NAME = so_long
NBONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = so_long.c readmapp.c mapchecker.c get_next_line.c get_next_line_utils.c ft_error.c heiwei.c movements.c protections.c backtracking.c destroyleaks.c playermovements.c
BSRC = ft_counter.c ft_spriteanim.c so_long_bonus.c readmapp.c mapchecker.c get_next_line.c get_next_line_utils.c ft_error.c heiwei.c upmove_bonus.c protections.c backtracking.c destroyleaks.c playermovements.c
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

fclean : clean
	rm -rf $(NAME) $(NBONUS)

re : fclean all

.PHONY : re fclean clean