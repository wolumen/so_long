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

void	deal_w(t_game *max);
void	deal_a(t_game *max);
void	deal_s(t_game *max);
void	deal_d(t_game *max);


int	deal_key(int key, void *param)
{
	t_game	*max;

	max = (t_game *)param;

	if (next_field_wall(key, max) == FALSE)
	{
		if (key == KEY_W)
			deal_w(max);
		if (key == KEY_S)
			deal_s(max);
		if (key == KEY_D)
			deal_d(max);
		if (key == KEY_A)
			deal_a(max);
	}
	if (key == KEY_ESC)
		ft_exit(max);
	return (0);
}

void	deal_w(t_game *max)
{
	mlx_put_image_to_window(max->mlx, max->win, max->world.background, max->figur.x, max->figur.y);
	max->figur.y -= max->figur.img_height;
	mlx_put_image_to_window(max->mlx, max->win, max->figur.img_u, max->figur.x, max->figur.y);
	display_steps(max);
	if (current_field(max) == 'C')
		collect_collectible(max);
	win(max);
}

void	deal_a(t_game *max)
{
	mlx_put_image_to_window(max->mlx, max->win, max->world.background, max->figur.x, max->figur.y);
	max->figur.x -= max->figur.img_width;
	mlx_put_image_to_window(max->mlx, max->win, max->figur.img_l, max->figur.x, max->figur.y);
	display_steps(max);
	if (current_field(max) == 'C')
		collect_collectible(max);
	win(max);
}

void	deal_s(t_game *max)
{
	mlx_put_image_to_window(max->mlx, max->win, max->world.background, max->figur.x, max->figur.y);
	max->figur.y += max->figur.img_height;
	mlx_put_image_to_window(max->mlx, max->win, max->figur.img_d, max->figur.x, max->figur.y);
	display_steps(max);
	if (current_field(max) == 'C')
		collect_collectible(max);
	win(max);
}

void	deal_d(t_game *max)
{
	mlx_put_image_to_window(max->mlx, max->win, max->world.background, max->figur.x, max->figur.y);
	max->figur.x += max->figur.img_width;
	mlx_put_image_to_window(max->mlx, max->win, max->figur.img_r, max->figur.x, max->figur.y);
	display_steps(max);	
	if (current_field(max) == 'C')
		collect_collectible(max);
	win(max);
}

// int	deal_mouse(int button, int x, int y, void *param)
// {
// 	t_game	*max;

// 	max = (t_game *)param;

	
// }
