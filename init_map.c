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

void	init_collectible(t_game *max, int i, int j)
{
	max->figur.collectible_found = 0;
	max->map.exit_x = j * max->world.world_height;
	max->map.exit_y = i * max->world.world_width;
}

void	fill_array(int file, t_game *max)
{
	char	sign;
	int		bytes;
	int		i;
	int		j;

	i = 0;
	j = 0;
	bytes = read(file, &sign, sizeof(sign));
	while (bytes > 0)
	{	
		if (sign != '\n')
		{	
			max->map.map_arr[i][j] = sign;
			if (sign == 'E')
				init_collectible(max, i, j);
			j++;
		}
		else
		{
			i++;
			j = 0;
		}
		bytes = read(file, &sign, sizeof(sign));
	}
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

void	get_rows_n_cols(t_game *max, char **argv)
{
	int		bytes;
	char	sign;
	int		file;

	max->map.rows = 1;
	max->map.cols = 1;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
		exit (-1);
	bytes = read(file, &sign, sizeof(sign));
	while (bytes > 0)
	{
		if (sign == '\n')
			max->map.rows += 1;
		max->map.cols += 1;
		bytes = read(file, &sign, sizeof(sign));
	}
	max->map.cols = (max->map.cols - max->map.rows) / max->map.rows;
	printf("rows: %d\ncols: %d\n", max->map.rows, max->map.cols);

	close(file);
}

void	init_map(t_game *max, char **argv)
{
	int	file;

	get_rows_n_cols(max, argv);

	allocate_array(max);

	file = open(argv[1], O_RDONLY);										// STEFFEN open eigentlich in fill_array function rein aber >25 Zeilen :(
	if (file == -1)
		exit (-1);
	fill_array(file, max);
	close(file);

	// int i, j;
    // for (i = 0; i < max->map.rows; i++) 
	// {
    //     for (j = 0; j < max->map.cols; j++) 
    //         printf("%c ", max->map.map_arr[i][j]);
    //     printf("\n");
    // }
}