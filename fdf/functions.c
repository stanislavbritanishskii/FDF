/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbritani <sbritani@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:13:08 by sbritani          #+#    #+#             */
/*   Updated: 2022/11/18 06:25:17 by sbritani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point*	make_point(int x, int y, int z, t_settings *settings)
{
	t_point	*res;

	res = malloc(sizeof(t_point));
	if (!res)
		return (NULL);
	res->x = x;
	res->y = y;
	res->z = z;
	res->color = GREEN;
	res->image = settings->im_ptr;
	return (res);
}

t_settings*	make_settings(int size_x, int size_y, char *name)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_settings	*res;

	res = malloc(sizeof(t_settings));
	if (!res)
		return (NULL);
	mlx_ptr = mlx_init(size_x, size_y, name, true);
	res->mlx_ptr = mlx_ptr;
	res->im_ptr = mlx_new_image(mlx_ptr, size_x, size_y);
	res->size_x = size_x;
	res->size_y = size_y;
	res->points_list = NULL;
	return (res);
}

void	put_point(t_point *point, t_settings *settings)
{
	mlx_put_pixel(point->image, point->x * settings->x_multyplier, (point->y) * settings->y_multyplier, 0x00FF0000);
}
void put_image(t_settings *settings)
{
	mlx_image_to_window(settings->mlx_ptr, settings->im_ptr, 0, 0);
}

void	put_line(t_point *start, t_point *end, t_settings *settings)
{
	double	deltaX;
	double	deltaY;
	double	pixelX;
	double	pixelY;
	int		pixels;

	deltaX = end->x - start->x;
	deltaY = end->y - start->y;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	pixelX = start->x;
	pixelY = start->y;
	while (pixels)
	{
		mlx_put_pixel(settings->im_ptr, pixelX, pixelY, GREEN);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}

void	read_points(char *file_name, t_settings *settings)
{
	char	*temp;
	char	**lst;
	int		fd;
	t_list	**res;
	int		x;
	int		y;
	t_list *h;
	t_point *p;
	fd = open(file_name, 'r');
	temp = get_next_line(fd);
	res = malloc(sizeof(t_list*));
	res[0] = NULL;
	x = 0;
	while (temp)
	{
		lst = ft_split(temp, " \n");
		y = 0;
		printf("%s\n", temp);
		while(lst[y])
		{
			printf("{%s}\n", lst[y]);
			ft_lstadd_back(res, ft_lstnew(make_point(x, y, ft_atoi(lst[y]), settings)));
			y++;
		}
		settings->y_points = y;
		p = (t_point*)(ft_lstlast(res[0])->content);
		printf("%d, %d, %d\n", p->x, p->y, p->z);
		temp = get_next_line(fd);
		x++;
	}
	settings->x_multyplier = settings-> size_x / x;
	settings->y_multyplier = settings-> size_y / y;
	settings->x_points = x;
	settings->points_list = res[0];
}