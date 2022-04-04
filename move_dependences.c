/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_dependences.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:49:08 by jpreissn          #+#    #+#             */
/*   Updated: 2022/04/04 10:49:08 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	next_field(int key, t_game *max)
{
	char	field;
	int		m;
	int		n;

	m = max->figur.y / max->figur.img_width;
	n = max->figur.x / max->figur.img_height;
	if (key == KEY_W)
		m = m - 1;
	if (key == KEY_S)
		m = m + 1;
	if (key == KEY_D)
		n = n + 1;
	if (key == KEY_A)
		n = n - 1;
	field = max->map.map_arr[m][n];
	return (field);
}

int	next_field_wall(int key, t_game *max)
{
	char field;

	field = next_field(key, max);
	if (field == WALL)
		return (TRUE);
	else
		return (FALSE);
}

void next_field_collectible(t_game *max)
{
	max->figur.collectible_found += 1;

	if (max->figur.collectible_found == max->map.collectible_count)
	{
		mlx_put_image_to_window(max->mlx, max->win, max->world.exit, max->map.exit_x, max->map.exit_y);
	}
}