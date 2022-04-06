/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_the_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:12:04 by jpreissn          #+#    #+#             */
/*   Updated: 2022/04/06 11:12:04 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// run with: gcc max_the_game.c libmlx.a -lX11 -lXext -lm && ./a.out
#include "so_long.h"

int	main(int argc, char **argv)
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

	// printf("nach init map\n");
	// printf("window width: %d, window height: %d\n", WINDOW_WIDTH, WINDOW_HEIGHT);

	max.win = mlx_new_window(max.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Spielewiese");
	// printf("aus dem Fenster\n");

	set_map(&max);
	// printf("aus der map\n");

	// mlx_key_hook(max.win, deal_key, &max);
	mlx_hook(max.win, 2, 1L << 0, deal_key, &max);
	// printf("carrots: %d\n", max.map.collectible_count);

	mlx_loop(max.mlx);

	return (0);
}
