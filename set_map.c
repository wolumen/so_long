/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:02:10 by jpreissn          #+#    #+#             */
/*   Updated: 2022/04/01 13:02:10 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map(t_game *max)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < max->map.rows)
	{
		while (j < max->map.cols)
		{			
			if (max->map.arr[i][j] == WALL)
				put_walls(max, i, j);
			else if (max->map.arr[i][j] == BKG || max->map.arr[i][j] == EXIT)
				mlx_put_image_to_window(max->mlx, max->win, max->world.bkg, \
					(max->world.width * j), (max->world.height * i));
			else if (max->map.arr[i][j] == COLL)
				put_collectibles(max, i, j);
			else if (max->map.arr[i][j] == PLAYER)
				put_player(max, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

void	put_walls(t_game *max, int i, int j)
{
	mlx_put_image_to_window(max->mlx, max->win, max->world.wall, \
		(max->world.width * j), (max->world.height * i));
}

void	put_collectibles(t_game *max, int i, int j)
{
	mlx_put_image_to_window(max->mlx, max->win, max->world.coll, \
		(max->world.width * j), (max->world.height * i));
	max->map.c_amount++;
}

void	put_player(t_game *max, int i, int j)
{
	mlx_put_image_to_window(max->mlx, max->win, max->figur.img_d, \
		(max->world.width * j), (max->world.height * i));
	max->figur.x = (max->world.width * j);
	max->figur.y = (max->world.height * i);
}
