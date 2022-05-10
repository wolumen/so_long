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

int	ft_exit(t_game *max)
{
	if (max->map.arr)
		free_map_array(max);
	if (max->win)
		mlx_destroy_window(max->mlx, max->win);
	free_images(max);
	mlx_loop_end(max->mlx);
	if (max->mlx)
	{
		mlx_loop_end(max->mlx);
		mlx_destroy_display(max->mlx);
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
		if (max->map.arr[i])
			free(max->map.arr[i]);
		i++;
	}
	if (max->map.arr)
		free(max->map.arr);
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
	if (max->world.bkg)
		mlx_destroy_image(max->mlx, max->world.bkg);
	if (max->world.coll)
		mlx_destroy_image(max->mlx, max->world.coll);
	if (max->world.exit)
		mlx_destroy_image(max->mlx, max->world.exit);
}
