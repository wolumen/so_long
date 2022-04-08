/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:54:31 by jpreissn          #+#    #+#             */
/*   Updated: 2022/03/31 13:54:31 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>			// printf
#include <unistd.h>
#include <stdlib.h>			// exit
#include <fcntl.h>			// für open

void	init_map(t_game *max, char **argv)
{
	int	file;

	file = open_file(max, argv);
	get_rows_n_cols(max, file);
	allocate_array(max);
	file = open_file(max, argv);
	fill_array(max, file);
	close(file);
	printf("in ini_map, shut.down: %d\n", max->err.shut_down);

	// int i, j;
	// for (i = 0; i < max->map.rows; i++) 
	// 	{
	// 	for (j = 0; j < max->map.cols; j++) 
	// 		printf("%c ", max->map.map_arr[i][j]);
	// 	printf("\n");
	// }
}

void	init_exit(t_game *max, int i, int j)
{
	max->map.collectible_count = 0;
	max->figur.collectible_found = 0;
	max->map.exit_x = j * max->world.world_height;
	max->map.exit_y = i * max->world.world_width;
}

void	fill_array(t_game *max, int file)
{
	char	sign;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (read(file, &sign, sizeof(sign)))
	{	
		if (sign != '\n')
		{	
			max->map.map_arr[i][j] = sign;
			if (sign == EXIT)
				init_exit(max, i, j);
			j++;
		}
		else
		{
			i++;
			j = 0;
		}
	}
	close(file);
}

void	allocate_array(t_game *max)
{
	int	i;

	max->map.map_arr = malloc(sizeof(char *) * max->map.rows);
	if (!max->map.map_arr)
		exit (-1);
	i = 0;
	while (i < max->map.rows)
	{
		max->map.map_arr[i] = malloc((sizeof(char) * max->map.cols) + 1);			// STEFFEN +1 für \n am Ende jeder Zeile´???
		if (!max->map.map_arr[i])
			exit (-1);
		i++;
	}
}

void	get_rows_n_cols(t_game *max, int file)
{
	char	sign;
	int		xmax;

	max->map.rows = 1;
	max->map.cols = -1;													// STEFFEN warum bei -1 starten? 

	while (read(file, &sign, sizeof(sign)))
	{
		if (sign != '\n')
		{
			max->map.cols += 1;
			if (max->map.rows == 1)
				xmax = max->map.cols;
		}
		else
		{
			if (max->map.cols != xmax)
				print_error("Map is not rectangle\n", max);
			max->map.rows += 1;
			max->map.cols = -1;
		}
	}
	max->map.cols = xmax;
	printf("rows: %d\ncols: %d\n", max->map.rows, max->map.cols);
	close(file);
}
