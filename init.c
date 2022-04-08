/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                       :+:      :+:    :+:  */
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
	max->map.arr = NULL;
	init_player(max);
	init_images(max);
	init_map(max, argv);
	init_window(max);
	init_errors(max);
	max->win = mlx_new_window(max->mlx, max->win_width, \
		max->win_height, "Playground");
}

void	init_player(t_game *max)
{
	max->figur.steps = 0;
	max->figur.x = 0;
	max->figur.y = 0;
}

void	init_images(t_game *max)
{
	max->figur.img_d = mlx_xpm_file_to_image(max->mlx, \
		"./img/p_d.xpm", &max->figur.img_width, &max->figur.img_height);
	max->figur.img_u = mlx_xpm_file_to_image(max->mlx, \
		"./img/p_u.xpm", &max->figur.img_width, &max->figur.img_height);
	max->figur.img_l = mlx_xpm_file_to_image(max->mlx, \
		"./img/p_l.xpm", &max->figur.img_width, &max->figur.img_height);
	max->figur.img_r = mlx_xpm_file_to_image(max->mlx, \
		"./img/p_r.xpm", &max->figur.img_width, &max->figur.img_height);
	max->world.wall = mlx_xpm_file_to_image(max->mlx, \
		"./img/wall.xpm", &max->world.width, &max->world.height);
	max->world.exit = mlx_xpm_file_to_image(max->mlx, \
		"./img/exit.xpm", &max->world.width, &max->world.height);
	max->world.bkg = mlx_xpm_file_to_image(max->mlx, \
		"./img/bkg.xpm", &max->world.width, &max->world.height);
	max->world.coll = mlx_xpm_file_to_image(max->mlx, \
		"./img/coll2.xpm", &max->world.width, &max->world.height);
}

void	init_window(t_game *max)
{
	max->win_width = max->map.cols * max->world.width;
	max->win_height = max->map.rows * max->world.height;
}

void	init_errors(t_game *max)
{
	max->err.borders = 0;
	max->err.rectangle = 0;
	max->err.c_count = 0;
	max->err.e_count = 0;
	max->err.p_count = 0;
	max->err.wrong_sign = 0;
}
