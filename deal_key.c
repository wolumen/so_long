/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:05:08 by jpreissn          #+#    #+#             */
/*   Updated: 2022/03/31 10:05:08 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int deal_key(int key, void *param)
{
	t_game	*max;

	max = (t_game *)param;
	// printf("jetzt wird der key ausgegeben:\n");
	// printf("%d\n", key);
	// printf("width: %d, higth: %d\n", max->figur.img_width, max->figur.img_height);
	// mlx_clear_window(max->mlx, max->win);
	// printf("steps: %d\n", max->figur.steps);
	// printf("x: %d, y: %d\n", max->figur.x, max->figur.y);
	if (key == KEY_W)
	{
		mlx_put_image_to_window(max->mlx, max->win, max->world.background, max->figur.x, max->figur.y);
		max->figur.y -= max->figur.img_height;
		mlx_put_image_to_window(max->mlx, max->win, max->figur.img_u, max->figur.x, max->figur.y);
		max->figur.steps += 1;
	}
	if (key == KEY_S)
	{
		mlx_put_image_to_window(max->mlx, max->win, max->world.background, max->figur.x, max->figur.y);
		max->figur.y += max->figur.img_height;
		mlx_put_image_to_window(max->mlx, max->win, max->figur.img_d, max->figur.x, max->figur.y);
		max->figur.steps += 1;
	}
	if (key == KEY_D)
	{
		mlx_put_image_to_window(max->mlx, max->win, max->world.background, max->figur.x, max->figur.y);
		max->figur.x += max->figur.img_width;
		mlx_put_image_to_window(max->mlx, max->win, max->figur.img_r, max->figur.x, max->figur.y);
		max->figur.steps += 1;
	}
	if (key == KEY_A)
	{
		mlx_put_image_to_window(max->mlx, max->win, max->world.background, max->figur.x, max->figur.y);
		max->figur.x -= max->figur.img_width;
		mlx_put_image_to_window(max->mlx, max->win, max->figur.img_l, max->figur.x, max->figur.y);
		max->figur.steps += 1;
	}
	if (key == KEY_ESC)
	{
		mlx_destroy_window(max->mlx, max->win);
		exit (0);
	}
	return (0);
}