NAME = so_long
NBONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = so_long.c readmapp.c mapchecker.c get_next_line.c get_next_line_utils.c ft_error.c heiwei.c ft_counter.c ft_spriteanim.c movements.c protections.c backtracking.c freeall.c destroyleaks.c playermovements.c
BSRC = ft_counter.c ft_spriteanim.c so_long.c readmapp.c mapchecker.c get_next_line.c get_next_line_utils.c ft_error.c heiwei.c movements.c protections.c backtracking.c freeall.c destroyleaks.c playermovements.c
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft.a

%.o : %.c so_long.h
	$(CC) -g $(CFLAGS) -Imlx -c $< -o $@

bonus : $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -lmlx -framework OpenGL -framework AppKit -o $(NBONUS) libft.a

clean :
	rm -rf $(OBJ) $(BOBJ)

fclean :
	rm -rf $(NAME) $(BOBJ)

re : fclean all

.PHONY : re fclean clean