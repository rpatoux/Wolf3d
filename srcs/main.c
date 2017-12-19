/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <rpatoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 12:39:18 by rpatoux           #+#    #+#             */
/*   Updated: 2017/10/10 20:58:11 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	free_all(t_var *my)
{
	ft_free_tab(my->map);
	mlx_destroy_image(my->mlx, my->img);
	my->mlx = NULL;
	my->win = NULL;
	my->img = NULL;
	free(my);
	my = NULL;
}

void	write_data_pixel(t_var *my, int x, int y, int color)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	b = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	r = (color & 0xFF);
	if (x >= 0 && y >= 0 && x < my->width && y < my->height)
	{
		my->data[y * my->size_line + x * (my->bpp / 8)] = r;
		my->data[y * my->size_line + x * (my->bpp / 8) + 1] = g;
		my->data[y * my->size_line + x * (my->bpp / 8) + 2] = b;
	}
}

void	ft_new_screen(t_var *my)
{
	mlx_destroy_image(my->mlx, my->img);
	my->img = mlx_new_image(my->mlx, my->width, my->height);
	my->data = mlx_get_data_addr(my->img, &my->bpp, &my->size_line,
	&my->endian);
}

int		main(int argc, char **argv)
{
	t_var	*my;

	if (argc != 2)
	{
		ft_putstr("Usage : ./wolf3d <Map Name>\n");
		exit(EXIT_FAILURE);
	}
	my = ft_init_struct(argv[1]);
	wolf(my);
	mlx_loop_hook(my->mlx, wolf, my);
	mlx_hook(my->win, KeyPress, KeyPressMask, key_funct, my);
	mlx_hook(my->win, KeyRelease, KeyReleaseMask, key_funct_bis, my);
	mlx_loop(my->mlx);
	return (0);
}
