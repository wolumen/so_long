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

	printf("collectibles amount: %d\n", max->map.collectible_count);

	field = next_field(key, max);
	if (field == WALL)
		return (TRUE);
	else
		return (FALSE);
}

// int next_field_collectible