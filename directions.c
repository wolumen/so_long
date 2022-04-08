/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:40:43 by jpreissn          #+#    #+#             */
/*   Updated: 2022/04/08 20:40:43 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	direction_up(t_game *max)
{	
	mlx_put_image_to_window(max->mlx, max->win, \
		max->world.bkg, max->figur.x, max->figur.y);
	max->figur.y -= max->figur.img_height;
	mlx_put_image_to_window(max->mlx, max->win, \
		max->figur.img_u, max->figur.x, max->figur.y);
	display_steps(max);
}

void	direction_left(t_game *max)
{	
	mlx_put_image_to_window(max->mlx, max->win, \
		max->world.bkg, max->figur.x, max->figur.y);
	max->figur.x -= max->figur.img_height;
	mlx_put_image_to_window(max->mlx, max->win, \
		max->figur.img_l, max->figur.x, max->figur.y);
	display_steps(max);
}

void	direction_down(t_game *max)
{	
	mlx_put_image_to_window(max->mlx, max->win, \
		max->world.bkg, max->figur.x, max->figur.y);
	max->figur.y += max->figur.img_height;
	mlx_put_image_to_window(max->mlx, max->win, \
		max->figur.img_d, max->figur.x, max->figur.y);
	display_steps(max);
}

void	direction_right(t_game *max)
{	
	mlx_put_image_to_window(max->mlx, max->win, \
		max->world.bkg, max->figur.x, max->figur.y);
	max->figur.x += max->figur.img_height;
	mlx_put_image_to_window(max->mlx, max->win, \
		max->figur.img_r, max->figur.x, max->figur.y);
	display_steps(max);
}
