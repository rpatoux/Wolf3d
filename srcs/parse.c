/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <rpatoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:02:40 by rpatoux           #+#    #+#             */
/*   Updated: 2017/10/10 21:01:27 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static int		verif_map_two(t_var *my)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (my->map[my->x_max - 1][++i])
		j++;
	if ((j != 23) || (my->x_max != 9))
		return (0);
	if ((my->r.pos_x != 4) || (my->r.pos_y != 4))
		return (0);
	i = 3;
	j = 4;
	if ((my->map[i][j] == '1') || (my->map[i - 1][j] == '1') ||
			(my->map[i + 1][j] == '1') || (my->map[i][j + 1] == '1') ||
			(my->map[i][j - 1] == '1'))
		return (0);
	return (1);
}

static int		verif_map(t_var *my, int i, int j)
{
	i = -1;
	while (my->map[my->x_max - 1][++i])
		if (my->map[my->x_max - 1][i] != '1')
			return (0);
	i = -1;
	while (my->map[++i][0] && i < my->x_max - 1)
		if (my->map[i][0] != '1')
			return (0);
	i = -1;
	while (my->map[++i][my->y_max - 1] && i < my->x_max - 1)
		if (my->map[i][my->y_max - 1] != '1')
			return (0);
	i = -1;
	while (++i < my->x_max - 1)
	{
		j = -1;
		while (++j < my->y_max - 1)
			if (my->map[i][j] != '1' && my->map[i][j] != '0')
				return (0);
	}
	return (1);
}

static int		parse_map(t_var *my)
{
	int		i;
	int		large;
	int		j;
	int		k;

	i = -1;
	k = -1;
	large = ft_strlen(my->map[0]);
	while (my->map[0][++k])
	{
		if (my->map[0][k] > '1')
			return (0);
	}
	while (my->map[++i])
	{
		j = ft_strlen(my->map[i]);
		if ((j != large) || (my->map[i][0] != '1' && my->map[i][0] != '0'))
			return (0);
	}
	return (1);
}

static void		recup_map(t_var *my, char *map_name)
{
	char	*file;

	if (ft_strcmp(map_name, "map"))
	{
		ft_putstr("Wrong Map Name\n");
		exit(EXIT_FAILURE);
	}
	if (!(file = get_file(map_name)))
		exit(EXIT_SUCCESS);
	my->x_max = ft_lenchar(file, '\n');
	if (!(my->map = ft_strsplit(file, '\n')))
		exit(EXIT_FAILURE);
	my->y_max = ft_strlen(my->map[0]);
	free(file);
	file = NULL;
	if (!parse_map(my) || !verif_map(my, 0, 0) || !verif_map_two(my))
	{
		ft_putstr("Wrong Map\n");
		exit(EXIT_FAILURE);
	}
}

t_var			*ft_init_struct(char *argv)
{
	t_var	*my;

	if (!(my = (t_var *)malloc(sizeof(t_var))))
		return (0);
	my->r.rot_speed = 0.05;
	my->moove = 0;
	my->r.speed = 0.1;
	my->tall = 1.00;
	my->r.pos_x = 4;
	my->r.pos_y = 4;
	my->r.plane_x = 0;
	my->r.plane_y = 0.70f;
	my->r.dir_x = -1;
	my->r.dir_y = 0;
	my->color = 0xB40404;
	my->width = 1200;
	my->height = 800;
	recup_map(my, argv);
	my->mlx = mlx_init();
	my->win = mlx_new_window(my->mlx, my->width, my->height, "Wolf3d");
	my->img = mlx_new_image(my->mlx, my->width, my->height);
	my->data = mlx_get_data_addr(my->img, &my->bpp,
			&my->size_line, &my->endian);
	return (my);
}
