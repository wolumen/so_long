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

char	current_field(t_game *max)
{
	char	field;
	int		m;
	int		n;

	m = max->figur.y / max->figur.img_width;
	n = max->figur.x / max->figur.img_height;
	field = max->map.map_arr[m][n];
	
	// printf("current field: %c\n", max->map.map_arr[m][n]);

	return (field);
}

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
	
	// printf("next field: %c\n", max->map.map_arr[m][n]);

	return (field);
}

void collect_collectible(t_game *max)
{
	int	m;
	int n;

	m = max->figur.y / max->figur.img_width;
	n = max->figur.x / max->figur.img_height;
	max->map.map_arr[m][n] = '0';
	max->figur.collectible_found += 1;

	if (max->figur.collectible_found == max->map.collectible_count)
	{
		mlx_put_image_to_window(max->mlx, max->win, max->world.exit, max->map.exit_x, max->map.exit_y);
	}
	// printf("carrot found: %d\n", max->figur.collectible_found);
	// printf("carrot count: %d\n", max->map.collectible_count);
}

void	win(t_game *max)
{
	if (max->figur.collectible_found >= max->map.collectible_count)
	{
		if (max->figur.x == max->map.exit_x && max->figur.y == max->map.exit_y)
		{
			write(2, YEL, ft_strlen(YEL));
			ft_putstr_fd("You ate all the carrots!\n", 1);
			write(2, WHITE, ft_strlen(WHITE));
			ft_exit(max);
		}
	}
}
