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


void	fill_array(int file, t_game *max)
{
	char	sign;
	int		bytes;
	int		i;
	int		j;
	printf("in fill_array0\n");

	i = 0;
	j = 0;
	while ((bytes = read(file, &sign, sizeof(sign))) > 0)
	{	
		if (sign != '\n')
		{	
			max->map.map_arr[i][j] = sign;
			j++;
		}
		else
		{
			i++;
			j = 0;
		}
	}
	printf("in fill_array1\n");
}

void allocate_array(t_game *max)
{
	int 	i;

	max->map.map_arr = malloc(sizeof(char*) * max->map.rows);
	if (!max->map.map_arr)
		exit (-1);
	printf("in allocate_array1\n");
	i = 0;
	while (i < max->map.rows)
	{
		max->map.map_arr[i] = malloc(sizeof(char) * max->map.cols);
		if (!max->map.map_arr[i])
			exit (-1);
		i++;
	}
	printf("in allocate_array2\n");
}

void init_map(t_game *max, char **argv)
{
	char	sign;
	int 	bytes;
	int 	file;

	max->map.rows = 1;
	max->map.cols = 0;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
		exit (-1);

	while ((bytes = read(file, &sign, sizeof(sign))) > 0)
	{
		if (sign == '\n')
			max->map.rows += 1;
		max->map.cols += 1;
	}
	max->map.cols = (max->map.cols - max->map.rows)  / max->map.rows;
	printf("rows: %d\ncols: %d\n", max->map.rows, max->map.cols);
	
	close(file);

	
	file = open(argv[1], O_RDONLY);
	if (file == -1)
		exit (-1);

	
	allocate_array(max);

	fill_array(file, max);
	

	int i, j;
    for (i = 0; i < max->map.rows; i++) 
	{
        for (j = 0; j < max->map.cols; j++) 
            printf("%c ", max->map.map_arr[i][j]);
        printf("\n");
    }
}
