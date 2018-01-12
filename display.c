/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:46:29 by mntumba           #+#    #+#             */
/*   Updated: 2018/01/09 15:48:58 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				pixel_put(t_wolf *wolf, char *data)
{
	if (!wolf->bpp || !wolf->size_line)
		exit(EXIT_FAILURE);
	data[(wolf->x * wolf->bpp / 8) +
		(wolf->y * wolf->size_line)] = wolf->color1;
	data[(wolf->x * wolf->bpp / 8) +
		(wolf->y * wolf->size_line) + 1] = wolf->color2;
	data[(wolf->x * wolf->bpp / 8) +
		(wolf->y * wolf->size_line) + 2] = wolf->color3;
	return (0);
}

int				expose_hook(t_wolf *wolf)
{
	mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->img, 0, 0);
	return (0);
}

void			ft_color(t_wolf *wolf, t_ray *ray, int w, float y)
{
	if (y > -w / 2 + W_W / 2 && y < w / 2 + W_W / 2 - 1 && ray->side == 0)
	{
		wolf->color1 = 173;
		wolf->color2 = 255;
		wolf->color3 = 47;
	}
	else if (y > -w / 2 + W_W / 2 && y < w / 2 + W_W / 2 - 1 && ray->side == 1)
	{
		wolf->color1 = 255;
		wolf->color2 = 69;
		wolf->color3 = 0;
	}
	else if (y > -w / 2 + W_W / 2 && y < w / 2 + W_W / 2 - 1 && ray->side == 3)
	{
		wolf->color1 = 255;
		wolf->color2 = 20;
		wolf->color3 = 147;
	}
	else
	{
		wolf->color1 = 40;
		wolf->color2 = 140 + y / 2;
		wolf->color3 = 40;
	}
}

void			ft_disp_wall(t_wolf *wolf)
{
	float	wall;

	wolf->x = -1;
	while (++wolf->x < W_H)
	{
		wolf->y = -1;
		wall = ft_raycasting(wolf, wolf->ray);
		while (++wolf->y < W_W)
		{
			ft_color(wolf, wolf->ray, abs((int)(W_W / wall)), wolf->y);
			pixel_put(wolf, wolf->data);
		}
	}
}

int				display(t_wolf *wolf)
{
	ft_disp_wall(wolf);
	mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->img, 0, 0);
	mlx_expose_hook(wolf->win, &expose_hook, wolf);
	return (0);
}
