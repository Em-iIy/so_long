#include "./mlx/mlx.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_image {
	void	*img;
	char	*relative_path;
	int		image_width;
	int		image_height;
}	t_image;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		i;
}	t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	vars->i--;
	printf("Hi from keyhook! %d\n", keycode);
	return (0);
}
int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	vars->i++;
	printf("Hi from mousehook! %d (%d, %d) i=%d\n", keycode, x, y, vars->i);
	return (0);
}


int	main(void)
{
	t_vars	vars;
	t_image	img;
	char	*relative_path64 = "desert-tile-64.xpm";
	char	*relative_path16 = "pico_8_march/backgound_tiles/pico-8-dessert-tiles.xpm";
	int		x,y;
	int		i,j;

	x = 64;
	y = 64;
	vars.i = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, x, y, "Hello!");
	// img = (t_image )malloc(sizeof(t_image *));
	img.img = mlx_xpm_file_to_image(vars.mlx, relative_path16, &img.image_width, &img.image_height);
	// printf("%p, %s, %d, %d\n", img.img, relative_path16, img.image_width, img.image_height);
	i = 0;
	while (i < x / img.image_width)
	{
		j = 0;
		while (j < y / img.image_height)
		{
			mlx_put_image_to_window(vars.mlx, vars.win, img.img, i * img.image_width, j * img.image_height);
			j++;
		}
		i++;
	}
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	// return (0);
}