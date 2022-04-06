/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_steps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:45:51 by jpreissn          #+#    #+#             */
/*   Updated: 2022/04/06 17:45:51 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_steps(t_game *max)
{
	max->figur.steps += 1;
	write(1, "moves: ", 7);
	ft_putnbr_fd(max->figur.steps, 1);
	write(1, "\n", 1);
}