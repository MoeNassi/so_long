/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:41:35 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/28 12:53:12 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>

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
	int			p1;
	int			doorp1;
	int			doorp2;
	int			p2;
	void		*secdoor;
	char		**arr;
}				t_var;

typedef struct s_text
{
	void	*player;
	void	*res;
	char	**blocks;
	char	*empty;
}				t_text;

char	**reading(char **av);
void	copy(t_var *read, t_text *big);
char	*get_next_line(int fd);
void	destroyleaks(t_var *remove, t_text *rem);
void	ft_animation(t_var *animsp);
void	upmove(t_var *up, int keycode);
void	mapchecker(t_var *check);
int		ft_error(int exp);
int		height(t_var *count);
int		weight(t_var *he);
void	ft_countmoves(t_var *first, int i);
void	checkcompo(t_var *scheck);
void	rightside(t_var *r);
void	upside(t_var *u);
void	downside(t_var *d);
void	leftside(t_var *l);
void	checkeverything(t_var *dcheck);
void	upmove_bonus(t_var *top, int keycode);
void	checkpaths(t_var *pcheck, t_text *seccheck);
void	checkpath1(t_var *first, t_text *sec);
int		ft_back(char **arr, int i, int j);

#endif
