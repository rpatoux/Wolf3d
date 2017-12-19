/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <rpatoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 18:45:12 by rpatoux           #+#    #+#             */
/*   Updated: 2017/10/10 20:55:57 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		ft_moove(t_var *my)
{
	if (my->moove & TURN_LEFT)
		ft_rotate_left(my);
	if (my->moove & TURN_RIGHT)
		ft_rotate_right(my);
	if (my->moove & WALK)
		ft_walk(my);
	if (my->moove & BACK)
		ft_back(my);
	if (my->moove & RIGHT)
		ft_right(my);
	if (my->moove & LEFT)
		ft_left(my);
}

int				key_funct(int keycode, t_var *my)
{
	if (keycode == 53)
	{
		free_all(my);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 69 && my->tall <= 6)
		my->tall += 0.1;
	if (keycode == 78 && my->tall >= 0.5)
		my->tall -= 0.1;
	if (keycode == 126)
		my->moove |= WALK;
	if (keycode == 125)
		my->moove |= BACK;
	if (keycode == 14)
		my->moove |= TURN_RIGHT;
	if (keycode == 13)
		my->moove |= TURN_LEFT;
	if (keycode == 123)
		my->moove |= LEFT;
	if (keycode == 124)
		my->moove |= RIGHT;
	return (1);
}

int				key_funct_bis(int keycode, t_var *my)
{
	if (keycode == 126)
		my->moove ^= WALK;
	if (keycode == 125)
		my->moove ^= BACK;
	if (keycode == 13)
		my->moove ^= TURN_LEFT;
	if (keycode == 14)
		my->moove ^= TURN_RIGHT;
	if (keycode == 124)
		my->moove ^= RIGHT;
	if (keycode == 123)
		my->moove ^= LEFT;
	return (1);
}

int				wolf(t_var *my)
{
	ft_new_screen(my);
	my->x = -1;
	while (++my->x < my->width)
		ray_cast_wall(my, my->x);
	ft_moove(my);
	mlx_put_image_to_window(my->mlx, my->win, my->img, 0, 0);
	return (0);
}
