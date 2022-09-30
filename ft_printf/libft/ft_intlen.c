/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:03:49 by tlahin            #+#    #+#             */
/*   Updated: 2022/05/09 17:14:59 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int i)
{
	int	count;

	count = 1;
	if (i == -2147483648)
		return ((size_t) 11);
	if (i < 0)
	{
		i = -i;
		count++;
	}
	while (i > 9)
	{
		i = i / 10;
		count++;
	}
	return ((size_t) count);
}
