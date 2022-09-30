/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:39:32 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/17 17:39:34 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(uintmax_t number, int base)
{
	char	*new;
	int		j;

	j = ft_number_size_base(number, base);
	new = (char *)malloc(sizeof(char) * j + 1);
	if (!new)
		return (NULL);
	new[j] = '\0';
	while (j--)
	{
		if ((number % base) < 10)
			new[j] = number % base + '0';
		else
			new[j] = number % base + 'a' - 10;
		number /= base;
	}
	return (new);
}
