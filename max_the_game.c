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
	t_game	max;												// die erste t_game Variable darf kein Pointer sein (no *max)

	if (argc < 2)
		exit (-8);

	init(&max, argv);
	// printf("nach init\n");

	max.win = mlx_new_window(max.mlx, max.win_width, max.win_height, "Spielewiese");
	// printf("aus dem Fenster\n");

	set_map(&max);
	// printf("aus der map\n");

	// mlx_key_hook(max.win, deal_key, &max);
	mlx_hook(max.win, 2, 1L << 0, deal_key, &max);
	// mlx_hook(win, ClientMessage, StructureNotifyMask, ft_exit, &max);

	mlx_loop(max.mlx);

	return (0);
}
