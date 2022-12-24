/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:41:35 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/24 18:03:46 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	void		*mlx_img;
	void		*p;
	void		*right;
	void		*up;
	void		*down;
	void		*left;
	void		*ptr;
	char		**map;
	int			x;
	int			y;
	int			count;
	int			checkp;
	void		*door;
	void		*door1;
	void*		secondcount;
	int			p1;
	int			doorp1;
	int			doorp2;
	int			p2;
	int			ene1;
	int			ene2;
	void		*secdoor;
	void		*near;
}				t_var;

typedef struct s_text
{
	void	*player;
	void	*res;
	char	**blocks;
	char	*empty;
}				t_text;

char	**reading(char **av);
void	copy(char **av, t_var *read, t_text *big);
char	*get_next_line(int fd);
void	ft_animation(t_var *animsp);
void	upmove(t_var *up, int keycode);
void	mapchecker(t_var *check);
int		ft_error(int exp);
void	enemy(t_var *first, int x, int y, int i, int j);
int		heiwei(t_var *count, char declare);
void	ft_countmoves(t_var *first, int i);

#endif
