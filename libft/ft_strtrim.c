/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:23:44 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/24 18:23:44 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim( char const *s1, char const *set)
{
	char	*trimmedstr;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmedstr = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!trimmedstr)
		return (NULL);
	i = 0;
	while (start < end)
		trimmedstr[i++] = s1[start++];
	trimmedstr[i] = 0;
	return (trimmedstr);
}

// Allocates (with malloc(3)) and returns a copy of ’s1’ 
// with the characters specified in ’set’ removed
// from the beginning and the end of the string.