/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:23:09 by jpreissn          #+#    #+#             */
/*   Updated: 2022/04/04 15:23:09 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_game *max)
{
	if (max->map.map_arr)
		free_map_array(max);
	if (max->win)
		mlx_destroy_window(max->mlx, max->win);
	free_images(max);
	mlx_loop_end(max->mlx);
	if (max->mlx)
	{
		mlx_loop_end(max->mlx);
		mlx_destroy_display(max->mlx);						// STEFFEN destroy display nach destroy window? Was heißt das?
		if (max->mlx)
			free(max->mlx);
	}
	exit (EXIT_SUCCESS);
}

void	free_map_array(t_game *max)
{
	int	i;

	i = 0;
	while (i < max->map.rows)
	{
		if (max->map.map_arr[i])
			free(max->map.map_arr[i]);
		i++;
	}
	if (max->map.map_arr)
		free(max->map.map_arr);
}

void	free_images(t_game *max)
{
	if (max->figur.img_d)
		mlx_destroy_image(max->mlx, max->figur.img_d);
	if (max->figur.img_u)
		mlx_destroy_image(max->mlx, max->figur.img_u);
	if (max->figur.img_l)
		mlx_destroy_image(max->mlx, max->figur.img_l);
	if (max->figur.img_r)
		mlx_destroy_image(max->mlx, max->figur.img_r);
	if (max->world.wall)
		mlx_destroy_image(max->mlx, max->world.wall);
	if (max->world.background)
		mlx_destroy_image(max->mlx, max->world.background);
	if (max->world.collectible)
		mlx_destroy_image(max->mlx, max->world.collectible);
	if (max->world.exit)
		mlx_destroy_image(max->mlx, max->world.exit);
}
