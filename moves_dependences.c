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

int	next_field_wall(int key, t_game *max)
{
	int m;
	int	n;

	m = (max->figur.x / max->figur.img_width) + 1;
	n = (max->figur.y / max->figur.img_height + 1);

	printf("max x: %d, max y: %d, m: %d, n: %d\n", max->figur.x, max->figur.y, m, n);
	printf("map: %c\n", max->map.map_arr[m][n]);

	if (key == KEY_W)
		n = n - 1;
	if (key == KEY_S)
		n = n + 1;
	if (key == KEY_D)
		m = m + 1;
	if (key == KEY_A)
		m = m - 1;
	if (max->map.map_arr[m][n] == WALL)
		return (TRUE);
	else
		return (FALSE);
}