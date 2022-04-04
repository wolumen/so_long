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

	m = max->figur.y / max->figur.img_width;
	n = max->figur.x / max->figur.img_height;

	printf("max x: %d, max y: %d, m: %d, n: %d\n", max->figur.x, max->figur.y, m, n);
	printf("map Spieler: %c\n", max->map.map_arr[m][n]);

	if (key == KEY_W)
		m = m - 1;
	if (key == KEY_S)
		m = m + 1;
	if (key == KEY_D)
		n = n + 1;
	if (key == KEY_A)
		n = n - 1;
	printf("m next: %d, n next: %d\n", m, n);
	printf("map Next: %c\n", max->map.map_arr[m][n]);
	
	if (max->map.map_arr[m][n] == WALL)
		return (TRUE);
	else
		return (FALSE);
}