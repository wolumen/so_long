/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:43:57 by jpreissn          #+#    #+#             */
/*   Updated: 2022/04/07 12:43:57 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_errors(t_game *max)
{
	parse_signs(max);
	parse_borders(max);
	if (max->err.p_count > 1)
		print_error("Too many players\n", max);
	if (max->err.p_count < 1)
		print_error("Too few players\n", max);
	if (max->err.e_count > 1)
		print_error("Too many exits\n", max);
	if (max->err.e_count < 1)
		print_error("Too few exits\n", max);
	if (max->err.c_count < 1)
		print_error("Map must have at least one collectible\n", max);
	if (max->err.rectangle > 0)
		print_error("Map must be rectangle\n", max);
	if (max->err.borders > 0)
		print_error("Map must be surrounded by walls\n", max);
	if (max->err.wrong_sign > 0)
		print_error("Unknown element on the map\n", max);
	if (max->err.shut_down > 0)
		ft_exit(max);
}

void	parse_signs(t_game *max)
{
	int		i;
	int		j;
	char	**sign;

	sign = max->map.map_arr;											// nur erstellt weil sonst Zeilen viel zu lang war
	i = 0;
	j = 0;
	while (i < max->map.rows)
	{
		while (j < max->map.cols)
		{
			if (sign[i][j] == PLAYER)
				max->err.p_count++;
			if (sign[i][j] == EXIT)
				max->err.e_count++;
			if (sign[i][j] == COLLECTIBLE)
				max->err.c_count++;
			if (ft_strchr(SIGNS, sign[i][j]) == NULL)
				max->err.wrong_sign++;
			j++;
		}
		i++;
		j = 0;
	}
}

void	parse_borders(t_game *max)
{
	int		i;
	char	**sign;

	sign = max->map.map_arr;											// nur erstellt weil sonst Zeilen viel zu lang war
	i = 0;
	while (i < max->map.rows)
	{
		if (sign[i][0] != WALL || sign[i][max->map.cols - 1] != WALL)
			max->err.borders++;
		i++;
	}
	i = 0;
	while (i < max->map.cols)
	{
		if (sign[0][i] != WALL || sign[max->map.rows - 1][i] != WALL)
			max->err.borders++;
		i++;
	}
}

void	print_error(char *str, t_game *max)
{
	write(2, RED, ft_strlen(RED));
	write(2, "Error\n", 6);
	write(2, YEL, ft_strlen(YEL));
	ft_putstr_fd(str, 2);
	write(2, WHITE, ft_strlen(WHITE));
	max->err.shut_down++;
}
