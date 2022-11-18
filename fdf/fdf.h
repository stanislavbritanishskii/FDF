/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbritani <sbritani@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:08:42 by sbritani          #+#    #+#             */
/*   Updated: 2022/11/18 06:25:10 by sbritani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libs/MLX42/include/MLX42/MLX42.h"
# include "libs/libft/libft.h"
# include "libs/get_next_line/get_next_line.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

# define RED 0xFFFF0000
# define BLUE 0xFF0000FF
# define GREEN 0xFF0FFFF0
# define WHITE 0xF0FFFFFF
# define BLACK 0xFF000000

typedef struct s_settings
{
	void		*mlx_ptr;
	mlx_image_t	*im_ptr;
	int			size_x;
	int			size_y;
	t_list		*points_list;
	int			x_points;
	int			y_points;
	int			x_multyplier;
	int			y_multyplier;
}		t_settings;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
	mlx_image_t*	image;
}		t_point;

t_point*		make_point(int x, int y, int z, t_settings *settings);
t_settings*		make_settings(int size_x, int size_y, char *name);
void			put_point(t_point *point, t_settings *settings);
void			put_line(t_point *start, t_point *end, t_settings *settings);
void 			put_image(t_settings *settings);
void			read_points(char *file_name, t_settings *settings);



#endif