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
			if (max->map.map_arr[i][j] == WALL)
				mlx_put_image_to_window(max->mlx, max->win, max->world.wall, (max->world.world_width * j), (max->world.world_height * i));
			else if (max->map.map_arr[i][j] == BACKGROUND)
				mlx_put_image_to_window(max->mlx, max->win, max->world.background, (max->world.world_width * j), (max->world.world_height * i));
			else if (max->map.map_arr[i][j] == COLLECTIBLE)
			{	
				mlx_put_image_to_window(max->mlx, max->win, max->world.collectible, (max->world.world_width * j), (max->world.world_height * i));
				max->map.collectible_count++;
			}
			else if (max->map.map_arr[i][j] == EXIT)
			{
				max->map.exit_x = (max->world.world_width * j);
				max->map.exit_y = (max->world.world_height * i);
			}
			else if (max->map.map_arr[i][j] == PLAYER)
			{
				mlx_put_image_to_window(max->mlx, max->win, max->figur.img_d, (max->world.world_width * j), (max->world.world_height * i));
				max->figur.x = (max->world.world_width * j);
				max->figur.y = (max->world.world_height * i);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
