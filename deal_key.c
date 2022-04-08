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

int	deal_key(int key, void *param)
{
	t_game	*max;

	max = (t_game *)param;
	if (next_field(key, max) != WALL)
		move(key, max);
	if (key == KEY_ESC)
		ft_exit(max);
	return (0);
}

void	move(int key, t_game *max)
{
	direction(key, max);
	if (current_field(max) == COLLECTIBLE)
		collect_collectible(max);
	win(max);
}

void	direction(int key, t_game *max)
{
	if (key == KEY_W)
	{	
		mlx_put_image_to_window(max->mlx, max->win, max->world.background, max->figur.x, max->figur.y);
		max->figur.y -= max->figur.img_height;
		mlx_put_image_to_window(max->mlx, max->win, max->figur.img_u, max->figur.x, max->figur.y);
		display_steps(max);
	}
	if (key == KEY_A)
	{	
		mlx_put_image_to_window(max->mlx, max->win, max->world.background, max->figur.x, max->figur.y);
		max->figur.x -= max->figur.img_height;
		mlx_put_image_to_window(max->mlx, max->win, max->figur.img_l, max->figur.x, max->figur.y);
		display_steps(max);
	}
	if (key == KEY_S)
	{	
		mlx_put_image_to_window(max->mlx, max->win, max->world.background, max->figur.x, max->figur.y);
		max->figur.y += max->figur.img_height;
		mlx_put_image_to_window(max->mlx, max->win, max->figur.img_d, max->figur.x, max->figur.y);
		display_steps(max);
	}
	if (key == KEY_D)
	{	
		mlx_put_image_to_window(max->mlx, max->win, max->world.background, max->figur.x, max->figur.y);
		max->figur.x += max->figur.img_height;
		mlx_put_image_to_window(max->mlx, max->win, max->figur.img_r, max->figur.x, max->figur.y);
		display_steps(max);
	}
}
