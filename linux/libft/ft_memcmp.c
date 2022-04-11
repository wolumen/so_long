/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:10:06 by jpreissn          #+#    #+#             */
/*   Updated: 2022/03/14 18:17:28 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	if (!str1 && !str2 && !n)
		return (0);
	ptr1 = (unsigned char *) str1;
	ptr2 = (unsigned char *) str2;
	i = 0;
	while (n--)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int arr2[] = {3, 4, 5, 6};
// 	int arr3[] = {3, 4, 5, 8};
// 	size_t n = 4;

// 	if (ft_memcmp(arr2, arr3, n * sizeof(int)) == 0)
// 		printf("memcmp Arrays are the same\n");
// 	else
// 		printf("memcmp Array are not the same\n");
// }
