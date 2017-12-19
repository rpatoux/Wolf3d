/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <rpatoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 12:40:28 by rpatoux           #+#    #+#             */
/*   Updated: 2017/10/10 21:02:34 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
# include <time.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include <OpenCL/opencl.h>
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>
# include "../libft/libft.h"

# define WALK (1 << 0)
# define BACK (1 << 1)
# define LEFT (1 << 2)
# define RIGHT (1 << 3)
# define TURN_RIGHT (1 << 4)
# define TURN_LEFT (1 << 5)

typedef struct	s_raycast
{
	double		weight;
	double		cur_dist;
	double		cur_floor_x;
	double		cur_floor_y;
	double		dist_play;
	double		dist_wall;
	double		floor_x;
	double		floor_y;
	double		speed;
	double		cam_x;
	double		cam_y;
	double		raydir_x;
	double		raydir_y;
	double		raypos_x;
	double		raypos_y;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		deltadist_x;
	double		deltadist_y;
	int			step_x;
	int			step_y;
	double		sizedist_x;
	double		sizedist_y;
	double		hit;
	int			side;
	double		perpwalldist;
	int			h_line;
	int			draw_start;
	int			draw_end;
	int			i;
	double		wallx;
	int			*text_width;
	int			*text_height;
	int			*text_size_line;
	int			*text_bpp;
	double		rot_speed;
}				t_raycast;

typedef struct	s_var
{
	int			width;
	int			height;
	void		*mlx;
	void		*win;
	void		*img;

	char		*data;

	int			size_line;
	int			bpp;
	int			endian;

	int			iter;
	int			colore;
	int			color;

	int			x;
	int			y;

	int			x_max;
	int			y_max;
	char		**map;

	int			map_x;
	int			map_y;

	int			moove;
	double		tall;
	t_raycast	r;
}				t_var;

t_var			*ft_init_struct(char *argv);
int				key_funct(int keycode, t_var *my);
int				key_funct_bis(int keycode, t_var *my);
int				wolf(t_var *my);
void			ray_cast_wall(t_var *my, int x);
void			ft_new_screen(t_var *my);
void			ft_walk(t_var *my);
void			ft_rotate_right(t_var *my);
void			ft_rotate_left(t_var *my);
void			ft_back(t_var *my);
void			ft_right(t_var *my);
void			ft_left(t_var *my);
void			write_data_pixel(t_var *my, int x, int y, int color);
void			draw_floor(t_var *my, int x, int y);
void			free_all(t_var *my);

#endif
