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
	if (key == KEY_ESC)
		ft_exit(max);
	if (next_field(key, max) != WALL)
		move(key, max);
	if (current_field(max) == COLL)
		collect_collectible(max);
	return (0);
}

void	move(int key, t_game *max)
{
	if (key == KEY_W)
		direction_up(max);
	if (key == KEY_A)
		direction_left(max);
	if (key == KEY_S)
		direction_down(max);
	if (key == KEY_D)
		direction_right(max);
	win(max);
}
