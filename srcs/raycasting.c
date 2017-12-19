/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <rpatoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:58:36 by rpatoux           #+#    #+#             */
/*   Updated: 2017/06/16 19:12:25 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		calc_wall(t_var *my)
{
	if (my->r.side <= 0)
		my->r.wallx = my->r.raypos_y + my->r.perpwalldist
		* my->r.raydir_y;
	else
		my->r.wallx = my->r.raypos_x + my->r.perpwalldist
		* my->r.raydir_x;
	my->r.wallx -= floor((my->r.wallx));
}

static void		calc_step(t_var *my)
{
	if (my->r.raydir_x < 0)
	{
		my->r.step_x = -1;
		my->r.sizedist_x =
		(my->r.raypos_x - my->map_x) * my->r.deltadist_x;
	}
	else
	{
		my->r.step_x = 1;
		my->r.sizedist_x =
		(my->map_x + 1.0 - my->r.raypos_x) * my->r.deltadist_x;
	}
	if (my->r.raydir_y < 0)
	{
		my->r.step_y = -1;
		my->r.sizedist_y =
		(my->r.raypos_y - my->map_y) * my->r.deltadist_y;
	}
	else
	{
		my->r.step_y = 1;
		my->r.sizedist_y =
		(my->map_y + 1.0 - my->r.raypos_y) * my->r.deltadist_y;
	}
}

static void		draw_wall(t_var *my, int x)
{
	int		y;

	y = my->r.draw_start - 1;
	while (++y < my->r.draw_end)
	{
		calc_wall(my);
		my->color = 0xB40404;
		if (my->r.side == 1)
			my->color = 0x3ADF00;
		else if (my->r.side == -1)
			my->color = 0x3A01DF;
		else if (my->r.side == 2)
			my->color = 0xFF0000;
		else
			my->color = 0x333333;
		write_data_pixel(my, x, y, my->color);
	}
}

static void		touch_wall(t_var *my)
{
	my->r.hit = 0;
	while (my->r.hit == 0)
	{
		if (my->r.sizedist_x <= my->r.sizedist_y)
		{
			my->r.sizedist_x += my->r.deltadist_x;
			my->map_x += my->r.step_x;
			my->r.side = (my->r.step_x == 1) ? 0 : -1;
		}
		else if (my->r.sizedist_x >= my->r.sizedist_y)
		{
			my->r.sizedist_y += my->r.deltadist_y;
			my->map_y += my->r.step_y;
			my->r.side = (my->r.step_y == 1) ? 2 : 1;
		}
		if (my->map[my->map_x][my->map_y] >= '1')
			my->r.hit = 1;
	}
}

void			ray_cast_wall(t_var *my, int x)
{
	my->r.cam_x = (2 * x / (double)my->width) - 1;
	my->r.raypos_x = my->r.pos_x;
	my->r.raypos_y = my->r.pos_y;
	my->r.raydir_x = my->r.dir_x + my->r.plane_x * my->r.cam_x;
	my->r.raydir_y = my->r.dir_y + my->r.plane_y * my->r.cam_x;
	my->map_x = my->r.raypos_x;
	my->map_y = my->r.raypos_y;
	my->r.deltadist_x = sqrt(1 + (my->r.raydir_y * my->r.raydir_y) /
	(my->r.raydir_x * my->r.raydir_x));
	my->r.deltadist_y = sqrt(1 + (my->r.raydir_x * my->r.raydir_x) /
	(my->r.raydir_y * my->r.raydir_y));
	calc_step(my);
	touch_wall(my);
	my->r.perpwalldist = (my->map_y - my->r.raypos_y +
	(1 - my->r.step_y) / 2) / my->r.raydir_y;
	if (my->r.side <= 0)
		my->r.perpwalldist = (my->map_x - my->r.raypos_x +
		(1 - my->r.step_x) / 2) / my->r.raydir_x;
	my->r.h_line = my->height / my->r.perpwalldist * my->tall;
	my->r.draw_start = (-my->r.h_line / 2 + my->height / 2);
	my->r.draw_end = (my->r.h_line / 2 + my->height / 2);
	my->r.draw_start < 0 ? my->r.draw_start = 0 : 0;
	my->r.draw_end >= my->height ? my->r.draw_end = my->height - 1 : 0;
	draw_wall(my, x);
	draw_floor(my, x, my->y);
}
