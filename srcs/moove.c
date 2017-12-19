/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <rpatoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:07:51 by rpatoux           #+#    #+#             */
/*   Updated: 2017/06/15 15:11:53 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		ft_back(t_var *my)
{
	double		x;
	double		y;

	x = (my->r.dir_x < 0 ? -0.15 : 0.15);
	y = (my->r.dir_y < 0 ? -0.15 : 0.15);
	if (my->map[(int)(my->r.pos_x - my->r.dir_x *
		my->r.speed - x)][(int)my->r.pos_y] < '1')
		my->r.pos_x -= my->r.dir_x * my->r.speed;
	if (my->map[(int)(my->r.pos_x)][(int)(my->r.pos_y -
		my->r.dir_y * my->r.speed - y)] < '1')
		my->r.pos_y -= my->r.dir_y * my->r.speed;
}

void		ft_walk(t_var *my)
{
	double		x;
	double		y;

	x = (my->r.dir_x < 0 ? -0.15 : 0.15);
	y = (my->r.dir_y < 0 ? -0.15 : 0.15);
	if (my->map[(int)(my->r.pos_x + my->r.dir_x *
		my->r.speed + x)][(int)my->r.pos_y] < '1')
		my->r.pos_x += my->r.dir_x * my->r.speed;
	if (my->map[(int)my->r.pos_x][(int)(my->r.pos_y +
		my->r.dir_y * my->r.speed + y)] < '1')
		my->r.pos_y += my->r.dir_y * my->r.speed;
}

void		ft_rotate_right(t_var *my)
{
	double olddirx;
	double oldplanex;

	olddirx = my->r.dir_x;
	my->r.dir_x = my->r.dir_x * cos(-my->r.rot_speed) -
	my->r.dir_y * sin(-my->r.rot_speed);
	my->r.dir_y = olddirx * sin(-my->r.rot_speed) +
	my->r.dir_y * cos(-my->r.rot_speed);
	oldplanex = my->r.plane_x;
	my->r.plane_x = my->r.plane_x * cos(-my->r.rot_speed)
	- my->r.plane_y * sin(-my->r.rot_speed);
	my->r.plane_y = oldplanex * sin(-my->r.rot_speed)
	+ my->r.plane_y * cos(-my->r.rot_speed);
}

void		ft_rotate_left(t_var *my)
{
	double olddirx;
	double oldplanex;

	olddirx = my->r.dir_x;
	my->r.dir_x = my->r.dir_x * cos(my->r.rot_speed)
	- my->r.dir_y * sin(my->r.rot_speed);
	my->r.dir_y = olddirx * sin(my->r.rot_speed)
	+ my->r.dir_y * cos(my->r.rot_speed);
	oldplanex = my->r.plane_x;
	my->r.plane_x = my->r.plane_x * cos(my->r.rot_speed)
	- my->r.plane_y * sin(my->r.rot_speed);
	my->r.plane_y = oldplanex * sin(my->r.rot_speed)
	+ my->r.plane_y * cos(my->r.rot_speed);
}
