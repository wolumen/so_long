/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:19:59 by jpreissn          #+#    #+#             */
/*   Updated: 2022/04/08 15:19:59 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *str, t_game *max)
{
	write(2, RED, ft_strlen(RED));
	write(2, "Error\n", 6);
	write(2, YEL, ft_strlen(YEL));
	ft_putstr_fd(str, 2);
	write(2, WHITE, ft_strlen(WHITE));
	max->err.shut_down++;
}

int	open_file(t_game *max, char **argv)
{
	int file;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{	
		print_error("map could not be opened\n", max);
		exit (-1);
	}
	return (file);
}
