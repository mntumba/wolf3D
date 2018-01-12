/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:43:39 by mntumba           #+#    #+#             */
/*   Updated: 2018/01/09 15:47:40 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move(t_wolf *wolf, int move)
{
	char	move1;
	char	move2;

	move1 = wolf->map[(int)(wolf->pos_x)][(int)(wolf->pos_y +
			wolf->dir_y * wolf->speed * move)];
	move2 = wolf->map[(int)(wolf->pos_x + wolf->dir_x *
			wolf->speed * move)][(int)(wolf->pos_y)];
	if (move == 1)
	{
		if (move1 == '0')
			wolf->pos_y += wolf->dir_y * wolf->speed;
		if (move2 == '0')
			wolf->pos_x += wolf->dir_x * wolf->speed;
	}
	if (move == -1)
	{
		if (move1 == '0')
			wolf->pos_y -= wolf->dir_y * wolf->speed;
		if (move2 == '0')
			wolf->pos_x -= wolf->dir_x * wolf->speed;
	}
}

void	rot(t_wolf *wolf, int move)
{
	wolf->plan_x = wolf->plan_x * cos(0.03 * move) - wolf->plan_x *
		sin(0.03 * move);
	wolf->plan_y = wolf->plan_x * sin(0.03 * move) + wolf->plan_y *
		cos(0.03 * move);
	wolf->dir_x = wolf->dir_x * cos(0.03 * move) - wolf->dir_y *
		sin(0.03 * move);
	wolf->dir_y = wolf->dir_x * sin(0.03 * move) + wolf->dir_y *
		cos(0.03 * move);
}

int		main(void)
{
	t_wolf	*wolf;

	if (!(wolf = (t_wolf*)malloc(sizeof(t_wolf))) ||
			!(wolf->ray = (t_ray*)malloc(sizeof(t_ray))))
		exit(EXIT_FAILURE);
	wolf->speed = 0.075;
	wolf->pos_x = 1.501;
	wolf->pos_y = 1.501;
	wolf->dir_x = 1;
	wolf->dir_y = 0;
	wolf->plan_x = 0;
	wolf->plan_y = 0.50;
	wolf->mlx = mlx_init();
	wolf->img = mlx_new_image(wolf->mlx, W_H, W_W);
	wolf->data = mlx_get_data_addr(wolf->img, &(wolf->bpp),
			&(wolf->size_line), &(wolf->endian));
	wolf->win = mlx_new_window(wolf->mlx, W_H, W_W, "Wolf3D");
	mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->img, 0, 0);
	ft_parser(wolf);
	mlx_hook(wolf->win, 2, 0, &key_hook, wolf);
	mlx_hook(wolf->win, 17, 0, &key_release, wolf);
	mlx_loop_hook(wolf->mlx, display, wolf);
	mlx_loop(wolf->mlx);
	return (0);
}
