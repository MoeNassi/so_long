/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:41:35 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/21 11:32:12 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	void		*mlx_img;
	void		*p;
	void		*player;
	void		*player1;
	void		*ptr;
	char		**map;
	int			x;
	int			y;
	int			count;
	void		*door1;
	int			secondcount;
	int			p1;
	int			doorp1;
	int			doorp2;
	int			p2;
}				t_var;

typedef struct s_text
{
	void	*player;
	void	*door;
	void	*res;
	char	**blocks;
	char	*empty;
}				t_text;

typedef struct s_movement
{
	void	*first;
	void	*second;
	void	*third;
	void	*fourth;
	void	*fifth;
	void	*sixth;
}				t_movement;

char	**reading(char **av);
void	copy(char **av, t_var *read, t_text *big);
char	*get_next_line(int fd);
void	mapchecker(t_var *check);
int		ft_error(int exp);
int		heiwei(t_var *count, char declare);

#endif
