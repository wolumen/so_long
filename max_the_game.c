// run with: gcc max_the_game.c libmlx.a -lX11 -lXext -lm && ./a.out


#include "so_long.h"

int main(int argc, char **argv)
{
	t_game	max;

	if (argc < 2)
		exit (-8);

	max.mlx = mlx_init();
	max.figur.steps = 0;
	max.figur.x = 0;
	max.figur.y = 0;

	init_images(&max);
	init_map(&max, argv);
	max.win = mlx_new_window(max.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Spielewiese");
	printf("aus dem Fenster\n");

	set_map(&max);
	printf("aus der map\n");

	// mlx_key_hook(max.win, deal_key, &max);
	mlx_hook(max.win, 2, 1L<<0, deal_key, &max);
	// mlx_hook()


	mlx_loop(max.mlx);

	return (0);
}
