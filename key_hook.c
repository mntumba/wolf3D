/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:35:56 by mntumba           #+#    #+#             */
/*   Updated: 2018/01/09 15:42:42 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_hook(int keycode, t_wolf *wolf)
{
	if (keycode == 124 || keycode == 123)
		(keycode == 124) ? rot(wolf, 1) : rot(wolf, -1);
	if (keycode == 126 || keycode == 125)
		(keycode == 126) ? move(wolf, 1) : move(wolf, -1);
	if (keycode == 53 && write(1, "End of Program\n", 15))
		exit(EXIT_SUCCESS);
	return (0);
}

int		key_release(void)
{
	write(1, "End of Program\n", 15);
	exit(EXIT_SUCCESS);
	return (0);
}
