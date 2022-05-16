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

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	max;

	max.err.shut_down = 0;
	check_args(&max, argc, argv);
	init(&max, argv);
	check_errors(&max);
	set_map(&max);
	instructions();
	mlx_hook(max.win, 2, 1, deal_key, &max);
	mlx_hook(max.win, 17, 4, ft_exit, &max);
	mlx_loop(max.mlx);
	return (0);
}
