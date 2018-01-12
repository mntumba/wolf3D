/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:42:21 by mntumba           #+#    #+#             */
/*   Updated: 2018/01/09 15:38:01 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		choose_dir(t_ray *ray, t_wolf *wolf)
{
	if (ray->ray_x < 0)
	{
		ray->step_x = -1;
		ray->dist_x = (wolf->pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->dist_x = (ray->map_x + 1.0 - wolf->pos_x) * ray->delta_x;
	}
	if (ray->ray_y < 0)
	{
		ray->step_y = -1;
		ray->dist_y = (wolf->pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->dist_y = (ray->map_y + 1.0 - wolf->pos_y) * ray->delta_y;
	}
}

static void		possible_move(t_wolf *wolf, t_ray *ray)
{
	int		stop;

	stop = 0;
	while (stop == 0)
	{
		if (ray->dist_x < ray->dist_y)
		{
			ray->dist_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->dist_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (wolf->map[ray->map_x][ray->map_y] != '0')
			stop = 1;
	}
}

float			ft_raycasting(t_wolf *wolf, t_ray *ray)
{
	ray->ray_x = wolf->dir_x + wolf->plan_x *
		(2 * wolf->x / (float)(W_H) - 1);
	ray->ray_y = wolf->dir_y + wolf->plan_y *
		(2 * wolf->x / (float)(W_H) - 1);
	ray->map_x = (int)(wolf->pos_x);
	ray->map_y = (int)(wolf->pos_y);
	ray->delta_x = sqrt(1 + pow(ray->ray_y, 2) / pow(ray->ray_x, 2));
	ray->delta_y = sqrt(1 + pow(ray->ray_x, 2) / pow(ray->ray_y, 2));
	choose_dir(ray, wolf);
	possible_move(wolf, ray);
	if (wolf->map[ray->map_x][ray->map_y] == '3')
		ray->side = 3;
	return ((ray->side == 0) ?
	fabs((ray->map_x - wolf->pos_x + (1 - ray->step_x) / 2) / ray->ray_x) :
	fabs((ray->map_y - wolf->pos_y + (1 - ray->step_y) / 2) / ray->ray_y));
}
