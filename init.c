/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:03:39 by jpreissn          #+#    #+#             */
/*   Updated: 2022/04/01 12:03:39 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	init(t_game *max, char **argv)
{
	max->mlx = mlx_init();
	max->map.map_arr = NULL;
	init_player(max);
	init_images(max);
	init_map(max, argv);
	init_window(max);
	init_errors(max);
}

void	init_player(t_game *max)
{
	max->figur.steps = 0;
	max->figur.x = 0;
	max->figur.y = 0;
}

void	init_images(t_game *max)
{
	max->figur.img_d = mlx_xpm_file_to_image(max->mlx, "./img/bun_down.xpm", &max->figur.img_width, &max->figur.img_height);
	max->figur.img_u = mlx_xpm_file_to_image(max->mlx, "./img/bun_up.xpm", &max->figur.img_width, &max->figur.img_height);
	max->figur.img_l = mlx_xpm_file_to_image(max->mlx, "./img/bun_left.xpm", &max->figur.img_width, &max->figur.img_height);
	max->figur.img_r = mlx_xpm_file_to_image(max->mlx, "./img/bun_right.xpm", &max->figur.img_width, &max->figur.img_height);
	max->world.wall = mlx_xpm_file_to_image(max->mlx, "./img/tree_b.xpm", &max->world.world_width, &max->world.world_height);
	max->world.exit = mlx_xpm_file_to_image(max->mlx, "./img/exit_b.xpm", &max->world.world_width, &max->world.world_height);
	max->world.background = mlx_xpm_file_to_image(max->mlx, "./img/background.xpm", &max->world.world_width, &max->world.world_height);
	max->world.collectible = mlx_xpm_file_to_image(max->mlx, "./img/carrot2_b.xpm", &max->world.world_width, &max->world.world_height);
}

void	init_window(t_game *max)
{
	max->win_width = max->map.cols * max->world.world_width;
	max->win_height = max->map.rows * max->world.world_height;
}

void	init_errors(t_game *max)
{
	max->err.borders = 0;
	max->err.rectangle = 0;
	max->err.c_count = 0;
	max->err.e_count = 0;
	max->err.p_count = 0;
	max->err.wrong_sign = 0;
	max->err.shut_down = 0;
}
