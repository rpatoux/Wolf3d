/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <rpatoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:09:34 by rpatoux           #+#    #+#             */
/*   Updated: 2017/06/15 17:30:12 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		calc_floor(t_var *my, int y)
{
	my->r.cur_dist = my->height / (2.0 * y - my->height);
	my->r.weight = (my->r.cur_dist - my->r.dist_play)
	/ (my->r.dist_wall - my->r.dist_play);
	my->r.cur_floor_x = my->r.weight * my->r.floor_x
	+ (1.0 - my->r.weight) * my->r.pos_x;
	my->r.cur_floor_y = my->r.weight * my->r.floor_y
	+ (1.0 - my->r.weight) * my->r.pos_y;
}

static void		calc_vect_floor(t_var *my)
{
	if (my->r.side == 0 && my->r.raydir_x > 0)
	{
		my->r.floor_x = my->map_x;
		my->r.floor_y = my->map_y + my->r.wallx;
	}
	else if (my->r.side == 0 && my->r.raydir_x < 0)
	{
		my->r.floor_x = my->map_x + 1.0;
		my->r.floor_y = my->map_y + my->r.wallx;
	}
	else if (my->r.side == 1 && my->r.raydir_y > 0)
	{
		my->r.floor_x = my->map_x + my->r.wallx;
		my->r.floor_y = my->map_y;
	}
	else
	{
		my->r.floor_x = my->map_x + my->r.wallx;
		my->r.floor_y = my->map_y + 1.0;
	}
}

static void		draw_sky(t_var *my, int x, int y)
{
	my->color = 0x848484;
	write_data_pixel(my, x, my->height - y, my->color);
}

void			draw_floor(t_var *my, int x, int y)
{
	calc_vect_floor(my);
	my->r.dist_wall = my->r.perpwalldist;
	my->r.dist_play = 0;
	if (my->r.draw_end < 0)
		my->r.draw_end = my->height - 1;
	y = my->r.draw_end;
	while (++y < my->height)
	{
		calc_floor(my, y);
		my->color = 0x585858;
		write_data_pixel(my, x, y, my->color);
		draw_sky(my, x, y);
	}
}
