/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:56:01 by mntumba           #+#    #+#             */
/*   Updated: 2018/01/09 15:30:15 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define W_H (600)
# define W_W (420)
# define BUF_SIZE 1

typedef struct	s_ray
{
	float		ray_x;
	float		ray_y;
	float		dist_x;
	float		dist_y;
	float		delta_x;
	float		delta_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			side;
}				t_ray;

typedef struct	s_wolf
{
	float		speed;
	float		pos_x;
	float		pos_y;
	float		dir_x;
	float		dir_y;
	float		plan_x;
	float		plan_y;
	int			x;
	int			y;
	int			bpp;
	int			size_line;
	int			endian;
	void		*mlx;
	void		*img;
	void		*win;
	char		*data;
	char		**map;
	int			move_left;
	int			move_right;
	int			move_up;
	int			move_down;
	int			color1;
	int			color2;
	int			color3;
	t_ray		*ray;
}				t_wolf;

void			ft_parser(t_wolf *wolf);
void			ft_disp_wall(t_wolf *wolf);
void			rot(t_wolf *wolf, int move);
void			move(t_wolf *wolf, int move);
int				key_hook(int keycode, t_wolf *wolf);
int				key_release(void);
float			ft_raycasting(t_wolf *wolf, t_ray *ray);
int				display(t_wolf *wolf);

#endif
