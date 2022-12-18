/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:41:35 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/18 17:25:34 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <stdlib.h>

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
	int			p1;
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

char	**reading(t_var *read, t_text *big);
char	*get_next_line(int fd);
void	mapchecker(t_var *check);

#endif
