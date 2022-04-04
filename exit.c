/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:23:09 by jpreissn          #+#    #+#             */
/*   Updated: 2022/04/04 15:23:09 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_game *max)
{
	int	i;

	i = 0;
	while (i < max->map.rows)
	{
		if (max->map.map_arr[i])
			free(max->map.map_arr[i]);
		i++;
	}
	free(max->map.map_arr);

	exit (EXIT_SUCCESS);
}