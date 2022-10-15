/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uintmax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:39:50 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/17 17:39:52 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_uintmax(uintmax_t number)
{
	char	*new;
	int		len;

	len = ft_intlen_max(number) + 1;
	new = ft_strnew(len + 1);
	if (!new)
		return (NULL);
	new[len] = '\0';
	len--;
	while (number >= 10)
	{
		new[--len] = (char)(number % 10 + '0');
		number /= 10;
	}
	new[--len] = (char)(number + '0');
	return (new);
}
