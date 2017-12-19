/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <rpatoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:27:02 by rpatoux           #+#    #+#             */
/*   Updated: 2017/06/15 15:11:45 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		ft_right(t_var *my)
{
	double		x;
	double		y;

	x = (my->r.plane_x < 0 ? -0.15 : 0.15);
	y = (my->r.plane_y < 0 ? -0.15 : 0.15);
	if (my->map[(int)(my->r.pos_x + my->r.plane_x *
		my->r.speed + x)][(int)my->r.pos_y] < '1')
		my->r.pos_x += my->r.plane_x * my->r.speed;
	if (my->map[(int)my->r.pos_x][(int)(my->r.pos_y +
		my->r.plane_y * my->r.speed + y)] < '1')
		my->r.pos_y += my->r.plane_y * my->r.speed;
}

void		ft_left(t_var *my)
{
	double		x;
	double		y;

	x = (my->r.plane_x < 0 ? -0.15 : 0.15);
	y = (my->r.plane_y < 0 ? -0.15 : 0.15);
	if (my->map[(int)(my->r.pos_x - my->r.plane_x *
		my->r.speed - x)][(int)my->r.pos_y] < '1')
		my->r.pos_x -= my->r.plane_x * my->r.speed;
	if (my->map[(int)my->r.pos_x][(int)(my->r.pos_y -
		my->r.plane_y * my->r.speed - y)] < '1')
		my->r.pos_y -= my->r.plane_y * my->r.speed;
}
