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
void	deal_W(t_game *max);
void	deal_A(t_game *max);
void	deal_S(t_game *max);
void	deal_D(t_game *max);


int deal_key(int key, void *param)
{
	t_game	*max;


	max = (t_game *)param;

	if (next_field(key, max) == 'C')
		next_field_collectible(max);
	
	if (next_field_wall(key, max) == FALSE)
	{
		if (key == KEY_W)
			deal_W(max);
		if (key == KEY_S)
			deal_S(max);
		if (key == KEY_D)
			deal_D(max);
		if (key == KEY_A)
			deal_A(max);
	}
	if (key == KEY_ESC)
	{
		mlx_destroy_window(max->mlx, max->win);
		ft_exit(max);
	}
	return (0);
}

void	deal_W(t_game *max)
{
	mlx_put_image_to_window(max->mlx, max->win, max->world.background, max->figur.x, max->figur.y);
	max->figur.y -= max->figur.img_height;
	mlx_put_image_to_window(max->mlx, max->win, max->figur.img_u, max->figur.x, max->figur.y);
	max->figur.steps += 1;
	if (max->figur.collectible_found >= max->map.collectible_count)											// STEFFEN >= weil collectibles endless gesammelt werden können :()
	{
		if (max->figur.x == max->map.exit_x && max->figur.y == max->map.exit_y)
			ft_exit(max);
	}
}

void	deal_A(t_game *max)
{
	mlx_put_image_to_window(max->mlx, max->win, max->world.background, max->figur.x, max->figur.y);
	max->figur.x -= max->figur.img_width;
	mlx_put_image_to_window(max->mlx, max->win, max->figur.img_l, max->figur.x, max->figur.y);
	max->figur.steps += 1;
	if (max->figur.collectible_found >= max->map.collectible_count)
	{
		if (max->figur.x == max->map.exit_x && max->figur.y == max->map.exit_y)
			ft_exit(max);
	}
}

void	deal_S(t_game *max)
{
	mlx_put_image_to_window(max->mlx, max->win, max->world.background, max->figur.x, max->figur.y);
	max->figur.y += max->figur.img_height;
	mlx_put_image_to_window(max->mlx, max->win, max->figur.img_d, max->figur.x, max->figur.y);
	max->figur.steps += 1;
	if (max->figur.collectible_found >= max->map.collectible_count)
	{
		if (max->figur.x == max->map.exit_x && max->figur.y == max->map.exit_y)
			ft_exit(max);
	}	
}

void	deal_D(t_game *max)
{
	mlx_put_image_to_window(max->mlx, max->win, max->world.background, max->figur.x, max->figur.y);
	max->figur.x += max->figur.img_width;
	mlx_put_image_to_window(max->mlx, max->win, max->figur.img_r, max->figur.x, max->figur.y);
	max->figur.steps += 1;	
	if (max->figur.collectible_found >= max->map.collectible_count)
	{
		if (max->figur.x == max->map.exit_x && max->figur.y == max->map.exit_y)
			ft_exit(max);
	}	
}
