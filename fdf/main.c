#include "fdf.h"


int main()
{
	t_settings*	settings;
	t_point*	point1;
	t_point*	point2;
	t_point*	point3;
	t_point		**points;

	settings = make_settings(500, 700, "window");
	read_points("map.txt", settings);
	t_list *x = settings->points_list;
	printf("in main\n");
	while(x)
	{
		t_point *p = (t_point*)(x->content);
		put_point(p, settings);
		x = x->next;
	}
	point1 = make_point(200, 250, 0, settings);
	point2 = make_point(250, 200, 0, settings);
	point3 = make_point(200, 300, 0, settings);
	put_line(point1, point2, settings);
	put_line(point2, point3, settings);
	put_line(point3, point1, settings);
	ft_putchar_fd('1', 1);
	put_image(settings);
	mlx_loop(settings->mlx_ptr);
}

// int perv_main()
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;

// 	mlx_ptr = mlx_init();
// 	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "ma_window");
// 	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, RED);
// 	mlx_pixel_put(mlx_ptr, win_ptr, 240, 250, GREEN);
// 	mlx_pixel_put(mlx_ptr, win_ptr, 260, 250, BLUE);
// 	mlx_loop(mlx_ptr);
// 	printf("hello, I am alive\n");
// 	return (0);

// }