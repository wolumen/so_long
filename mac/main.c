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
	max.err.shut_down = 0;
	check_args(&max, argc, argv);
	init(&max, argv);
	check_errors(&max);
	set_map(&max);
	mlx_hook(max.win, 2, 1L << 0, deal_key, &max);				// 2  KeyPress				(1L<<0)	KeyPressMask
	mlx_hook(max.win, 17, 1L << 2, ft_exit, &max);				// 17 on Destroy - red X	(1L<<2)	ButtonPressMask
	mlx_loop(max.mlx);
	return (0);
}
