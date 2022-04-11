/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:09:21 by jpreissn          #+#    #+#             */
/*   Updated: 2022/04/07 21:09:21 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(t_game *max, int argc, char **argv)
{	
	int	file;

	if (argc < 2)
	{	
		print_error("to few arguments\n", max);
		ft_putstr_fd("Usage: ./so_long maps/<map.ber>\n", 2);
	}
	if (ft_strrncmp(argv[1], ".ber", 4))
		print_error("map: wrong extension, use .ber\n", max);
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{	
		print_error("map could not be opened\n", max);
		exit (-1);
	}
}
